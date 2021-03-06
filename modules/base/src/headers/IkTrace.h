#ifndef _IKNOW_BASE_IKTRACE_H
#define _IKNOW_BASE_IKTRACE_H

#define NO_UCHAR_TYPE
#include <vector>
#include <list>
#include <utility>
#include "IkTypes.h"
#include <sstream>
#include <string>
#include "IkStringEncoding.h"

#ifdef ISC_IRIS
#include "utlCacheList.h"
typedef CacheList TraceListType;
#else
typedef std::list<std::string> Utf8List; // alternative for utlCacheList
typedef Utf8List TraceListType;
#endif


namespace iknow {
  namespace base {
    template<typename TList>
    class IkTrace {
    public:
      typedef std::pair<iknow::base::String, TList> Item;
      typedef std::vector<Item> Items;
      void Add(const iknow::base::String& type, const TList& value) {
	    items_.push_back(Item(type, value));
      }
      template<typename T, typename V>
	  void Add(const T& t, const V& v) {
	        Add(ToString(t), v);
      }
      typename Items::const_iterator begin() const {
	    return items_.begin();
      }
      typename Items::const_iterator end() const {
	    return items_.end();
      }
    private:
      iknow::base::String ToString(size_t n) {
	    std::stringstream ss;
	    ss << n;
	    return ToString(ss.str());
      }
      iknow::base::String ToString(const iknow::base::String& s) {
	    return s;
      }
      iknow::base::String ToString(const std::string& s) {
	    return iknow::base::IkStringEncoding::UTF8ToBase(s);
      }
      Items items_;
    };
  }
}
#endif //_IKNOW_BASE_IKTRACE_H
