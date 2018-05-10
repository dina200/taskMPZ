#include <iostream>
#include "simc.h"

int main() {
	pstorage ob, ts, sts, svs;
	initlist(50); //* 5 * 5);
	newstorage(ob, "Otlivochnie bloki", 14);
	newstorage(ts, "Tokarnie stanki", 5);
	newstorage(sts, "Strogal'nie stanki", 4);
	newstorage(svs, "Sverliynie stanki", 8);
	initcreate(1,0);
	initcreate(1,0);
//	initcreate(11,0);
	starttrace();	
	while (systime < 8 * 60) { //5 * 40
		plan();
		switch(sysevent) {
			case 1: if(randab(0,1,v1) > 0.24) {
					trans->pb[0] = true;
					enter(ob, 1); 					
					break;
				}
				else {						
					trans->pb[0] = false;	
					enter(svs, 1);			
					break;
				}			
			case 2: if (trans->pb[0]) delayt (125); 
					else  delayt (105);
					break;					
			case 3: if (trans->pb[0]) leave(ob, 1); 
					else  leave(svs, 1);
					break; 
			
			case 4: if (trans->pb[0]) enter (sts, 1); 
					else  enter (ts, 1);
					break;					
			case 5: if (trans->pb[0]) delayt (35); 
					else  delayt (90);
					break;					
			case 6: if (trans->pb[0]) leave(sts, 1); 
					else  leave(ts, 1);
					break;
					
			case 7: if (trans->pb[0]) enter (ts, 1); 
					else  enter (sts, 1);
					break;					
			case 8: if (trans->pb[0]) delayt (20); 
					else  delayt (65);
					break;					
			case 9: if (trans->pb[0]) leave(ts, 1); 
					else  leave(sts, 1);
					break;
			case 10: next(1);
		}
	
	}
	printall();
	system("pause");
	return 0;
}
