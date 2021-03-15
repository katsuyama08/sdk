/*
 * ���Υե������ tecsgen �ˤ��ƥ�ץ졼�ȤȤ��Ƽ�ư��������ޤ���
 * ���Υե�������Խ����ƻ��Ѥ��뤳�Ȥ��տޤ���Ƥ��ޤ���
 * tecsgen �κƼ¹Ԥˤ���񤭤���Ƥ��ޤ����ᡢ�̾�
 *   gen/tEIDTaskMain_templ.c => src/tEIDTaskMain.c
 * �Τ褦��̾��, �ե�������ѹ����Ƥ��齤�����ޤ�
 */
/* #[<PREAMBLE>]#
 * #[<...>]# ���� #[</...>]# �ǰϤޤ줿�����Ȥ��Խ����ʤ��Ǥ�������
 * tecsmerge �ˤ��ޡ����˻��Ѥ���ޤ�
 *
 * °�����������ޥ��� #_CAAM_#
 * appEID           char [5][37]     VAR_appEID      
 *
 * �ƤӸ��ؿ� #_TCPF_#
 * call port: cEID signature: sEID context:task
 *   void           cEID_compare( const char* str );
 * call port: cSetfn signature: sSetfn context:task
 *   void           cSetfn_set( subscript, int id );
 *       subscript:  0...(NCP_cSetfn-1)
 *
 * #[</PREAMBLE>]# */

/* �ץ�ȥ�����������ѿ�������򤳤��˽񤭤ޤ� #_PAC_# */
#include "tEIDTaskMain_tecsgen.h"
#include <t_syslog.h>
#include <ev3api_eid.h>

#ifndef E_OK
#define	E_OK	0		/* success */
#define	E_ID	(-18)	/* illegal ID */
#endif

/* �������ؿ� #_TEPF_# */
/* #[<ENTRY_PORT>]# eTaskBody
 * entry port: eTaskBody
 * signature:  nLUM_sTaskBody
 * context:    task
 * #[</ENTRY_PORT>]# */

/* #[<ENTRY_FUNC>]# eTaskBody_main
 * name:         eTaskBody_main
 * global_name:  tEIDTaskMain_eTaskBody_main
 * oneway:       false
 * #[</ENTRY_FUNC>]# */
void
eTaskBody_main()
{

  char appEID[1][37] = {"7c98926c-8c42-4f8d-86c8-05e4fbf472d5"};

  int i;
  int id = 0;

  for(i=0; i<1; i++){
    id = compare(appEID[i]);

    if(id != 0){
      syslog(LOG_EMERG, "tfn_base of %s is %d", appEID[i], id);
      cSetfn_set(1, id);
    }else{
      syslog(LOG_EMERG, "EID %s is incorrect", appEID[i]);
    }
  }
  
}

/* #[<POSTAMBLE>]#
 *   �����겼����������ؿ���񤭤ޤ�
 * #[</POSTAMBLE>]#*/
