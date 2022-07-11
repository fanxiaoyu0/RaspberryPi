#include "branch_predictor.h"

/* ************** */
/* TASK3: 2019013273 */
/* ************** */

typedef struct {
  unsigned short pc;
  unsigned short target;
} BTBEntry;

char* predictor_space;
unsigned short GHR;
char* PHT;
BTBEntry* BTB;
unsigned short BTB_pointer;

void branch_predictor_init(void) {
    predictor_space = vmalloc(PREDICTOR_SIZE * sizeof(char));
    // TODO: other code if necessary
    PHT = predictor_space;
    int i;
    for (i = 0; i < 512; i++) PHT[i] = 0x55;
    BTB = (BTBEntry*) (predictor_space + 512);
    GHR = 0;
    BTB_pointer = 0;
}

va_t get_from_branch_predictor(reg64_t pc) {
    // TODO: once your branch predictor get an instruction address, it should give a predicted target address
    unsigned short PC = (unsigned short)(pc & 0xffff);
    unsigned short pht_index   = (PC) & 0x7ff;
    unsigned short pht_counter = (PHT[pht_index/4]>>(pht_index%4))&3;
    if(pht_counter==0 || pht_counter==1) return pc+4;
    else{
        int i;
        for (i=0;i<128;i++){
            if(BTB[i].pc==PC) return (pc&(~(0xffff)))+(unsigned long long)(BTB[i].target);
        }
    }
    return pc+4;
}

void set_pht(unsigned short index, unsigned short value){
    PHT[index/4] = (PHT[index/4]&(~(3<<(index%4)))) | ((value&3)<<(index%4));
}

void branch_predictor_update(reg64_t pc, va_t target) {
    // TODO: the debugger will give the correct target address once a branch instrucion executed, and you need to update the branch predictor
    unsigned short PC = (unsigned short)(pc & 0xffff);
    unsigned short pht_index   = (PC) & 0x7ff;
    unsigned short pht_counter = (PHT[pht_index/4]>>(pht_index%4))&3;
    if(target==pc+4){
        GHR=GHR<<1;
        if (pht_counter==0) set_pht(pht_index,0);
        else set_pht(pht_index,pht_counter-1);
    }
    else{
        GHR=(GHR<<1)+1;
        if (pht_counter==3) set_pht(pht_index,3);
        else set_pht(pht_index,pht_counter+1);
        int flag=0;
        int i=0;
        for (i=0;i<128;i++){
            if(BTB[i].pc==PC){
                BTB[i].target=(unsigned short)(target & 0xffff);
                flag=1;
                break;
            }
        }
        if(flag==0){
            BTB[BTB_pointer].pc=PC;
            BTB[BTB_pointer].target=(unsigned short)(target & 0xffff);
            BTB_pointer=(BTB_pointer+1)%128;
        }
    }
}

void branch_predictor_release(void) {
    vfree(predictor_space);
    // TODO: other code if necessary
}
