
#include <string.h>
#include "ev3api_eid.h"
#include "extsvc_fncode.h"
#define MAX 2

int compare(char str[]){

  char baseEID[MAX][37] = {"7c98926c-8c42-4f8d-86c8-05e4fbf472d5",
			   "a210ea67-a942-4bef-af7f-9ec1c627aad7"};
  int SVCID[MAX] = {TFN_TECSGEN_ORIGIN + 1,
		    TFN_TECSGEN_ORIGIN + 10};
  
  int i, num;
  int len = 0;

  for(i=0; i<MAX; i++){
    if(strcmp(str, baseEID[i]) == 0){
      num = SVCID[i];
      break;
    }

    len++;

    if(len == MAX){
      num = 0;
      break;
    }
  }

  return num;

}
