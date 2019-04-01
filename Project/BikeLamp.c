
#include <at89x52.h>
#include <absacc.h>
void on(void){
			XBYTE[0xF030]=0x7F;
			XBYTE[0xF038]=0x49;
			P1_6 = 0;	
}
void slowblinking(void){
			int j,k;
			XBYTE[0xF030]=0x7F;
			XBYTE[0xF038]=0x49;
			P1_6=0;
			for(j=0;j<3000;j++){for(k=0;k<25;k++){}}
			P1_6=1;
			for(j=0;j<3000;j++){for(k=0;k<10;k++){}}
}	
void fastblinking(void){
			int j,k;
			XBYTE[0xF030]=0x7F;
			XBYTE[0xF038]=0x49;
			P1_6=0;
			for(j=0;j<3000;j++){for(k=0;k<10;k++){}}
			P1_6=1;
			for(j=0;j<3000;j++){for(k=0;k<10;k++){}}
}

void off(void){
P1_6=1;
}
void main() {
	while(1){
		while(XBYTE[0xF021]==0xFF){}
		while(XBYTE[0xF021]==0xFE){}
		while(XBYTE[0xF021]==0xFF){
			//on
			on();
		}
		while(XBYTE[0xF021]==0xFE){}
		while(XBYTE[0xF021]==0xFF){
			//slowblinking
			slowblinking();
		}
		while(XBYTE[0xF021]==0xFE){}
		while(XBYTE[0xF021]==0xFF){
			//fastblinking
			fastblinking();
		}
		while(XBYTE[0xF021]==0xFE){}
		while(XBYTE[0xF021]==0xFF){
		off();
		}
	}
}