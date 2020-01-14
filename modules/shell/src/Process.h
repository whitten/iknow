// Process.h: interface for the CProcess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROCESS_H__DEBE34C9_1852_4C92_8C4B_D56CAD83D936__INCLUDED_)
#define AFX_PROCESS_H__DEBE34C9_1852_4C92_8C4B_D56CAD83D936__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//core includes
#include "IkKnowledgebase.h"
#include "IkOntology.h"
#include "IkIndexInput.h"
#include "IkIndexOutput.h"
#include "OutFunc.h"
#include "Export.h"
#include "IkCore.h"
#include "IkStemmer.h"
namespace iknow
{
  namespace shell
  {

    //! CProcess executes the required task with the correct parameters
    /*!
     *	Executes the actual task at hand
     */
    class SHELL_API CProcess
    {
    public:
      /*!
       *	Constructor
       *	\param languageKbMap: map of multiple knowledgebases, for multiple languages
       *	\param pOutput: pointer to the processoutput
       */
	typedef std::map<iknow::base::String, iknow::core::IkKnowledgebase*> type_languageKbMap;
	CProcess(const std::map<iknow::base::String, iknow::core::IkKnowledgebase*>& languageKbMap);

      virtual ~CProcess(); /*!< Destructor */
						
      /*!
       *	Start the indexing
       *	\param strTextInput: the inputstring
       *	\param nMaxConceptSize: the maximum concept-size, 
       *	\param	nFlag: flag that specifies what needs to be shown in the output
       *	\exception CProcessException: UNKNOWN ERROR
       */
      //TODO, TRW: Three boolean parameters are a bad way to parameterize this. Also, input should be const, but bizarre IkInput prevents this
      void IndexFunc (const iknow::base::String& input, OutputFunc func, void *userdata, 
                      bool tracing_enabled = 0, 
                      bool merge_relations = 1, 
                      bool allow_long_sentences = 1, 
                      bool delimited_sentences_mode = 0, 
                      bool make_summary = 0, 
                      size_t max_concept_cluster_length = 0, 
                      iknow::core::IkKnowledgebase *user_dictionary = NULL,
			          Stemmer *stemmer = NULL
      );
	  // Now with text annotations...
	  void IndexFunc(iknow::core::IkIndexInput& text_input, OutputFunc func, void *userdata, bool bDomAndProx=false);

    protected:
      iknow::core::IkCore* m_pCore;
	  bool m_IsJapaneseInvolved;
	  bool m_tracing_enabled;
	  bool m_merge_relations;
	  bool m_allow_long_sentences;
	  bool m_delimited_sentences_mode;
	  bool m_make_summary;
	  size_t m_max_concept_cluster_length;
	  iknow::core::IkKnowledgebase *m_user_dictionary;
	  Stemmer *m_stemmer;
    };
  }
}

#endif // !defined(AFX_PROCESS_H__DEBE34C9_1852_4C92_8C4B_D56CAD83D936__INCLUDED_)

