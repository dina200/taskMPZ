#include <iostream>
#include "simc.h"

int main() {
	pstorage ob, ts, sts, svs;
	initlist(50 * 5 * 5);
	pqueue qob;
	pqueue qts;
	pqueue qsts;
	pqueue qsvs;
	newstorage(ob, "Otlivochnie bloki", 14);
	newstorage(ts, "Tokarnie stanki", 5);
	newstorage(sts, "Strogal'nie stanki", 4);
	newstorage(svs, "Sverliynie stanki", 8);
	newqueue(qob, "Ochered' dlya otlivochnih blokov");
	newqueue(qts, "Ochered' dlya tokarnih stankov");
	newqueue(qsts, "Ochered' dlya srogal'nih stankov");
	newqueue(qsvs, "Ochered' dlya sverliynie stankov");
	initcreate(1,0);
	//starttrace();
	while (systime < 8 * 60 * 5 * 5) { //
		plan();
		switch(sysevent) {
			case 1: create(8*60/50); break;
			
			case 2:if(randab(0,1,v1) > 0.24) {
						trans->pb[0] = true;
						inqueue(qob);
					}
					else {						
						trans->pb[0] = false;	
						inqueue(qsvs);					
					}	
					break;
			case 3: if(trans->pb[0]) enter(ob, 1); 	
					else enter(svs, 1);	
					break;				
			case 4: if(trans->pb[0]) outqueue(qob); 
					else outqueue(qsvs);
					break;			
			
			case 5: if (trans->pb[0]) delayt (125); 
					else  delayt (105);
					break;					
			case 6: if (trans->pb[0]) leave(ob, 1); 
					else  leave(svs, 1);
					break; 
			
			
			
			case 7: if(trans->pb[0]) inqueue(qsts);
					else inqueue(qts);
					break;		
			case 8: if (trans->pb[0]) enter (sts, 1); 
					else  enter (ts, 1);
					break;			
			case 9: if(trans->pb[0]) outqueue(qsts); 
					else outqueue(qts);
					break;				
			case 10: if (trans->pb[0]) delayt (35); 
					else  delayt (90);
					break;										
			case 11: if (trans->pb[0]) leave(sts, 1); 
					else  leave(ts, 1);
					break;
					
					
															
			case 12:if(trans->pb[0]) inqueue(qts);
					else inqueue(qsts);
					break;				
			case 13: if (trans->pb[0]) enter (ts, 1); 
					else  enter (sts, 1);
					break;	
			case 14: if(trans->pb[0]) outqueue(qts); 
					else outqueue(qsts);
					break;									
			case 15: if (trans->pb[0]) delayt (20); 
					else  delayt (65);
					break;					
			case 16: if (trans->pb[0]) leave(ts, 1); 
					else  leave(sts, 1);
					break;
					
			case 17:destroy(); break;
		}
	
	}
	printall();
	system("pause");
	return 0;
}
