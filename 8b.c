#include<stdio.h>
#include<string.h>
int main()
{
    int distance_between_two_routers;
	printf("\nEnter the distance between two routers:");
	scanf("%d",&distance_between_two_routers);
	while(1){
            int propagation_delay=0,propagation_velacity=0,roundtrip_time,time_out,length_of_packet=0;
	char a[100];
	printf("\n\n\n enter a message to send---->");
     scanf("%s",&a);
	length_of_packet=strlen(a);
	//printf("%d",length_of_packet);
	propagation_velacity=30000*length_of_packet	;
	propagation_delay=distance_between_two_routers/propagation_velacity;

   int c, d,count=0;
   if (propagation_delay>=2){
        printf("\n\n \t\t\t\t\t sending...\n\n");
   for (c = 1; c <= propagation_velacity/2; c++){
       for (d = 1; d <=propagation_velacity; d++)
       {  count++;
          if( count==(propagation_velacity/2*propagation_velacity)){
            printf("\n \t\t\t\t\t time out\n\n");
            printf("Resend it :--->");
           scanf("%s",&a);
           printf("Receiver receives a messages:%s",&a);
          }

       }
   }
   }
   else{
       int count =0;
         printf("\n\n\n \t\t\t\t\t sending...\n\n\n");
   for (c = 1; c <= propagation_velacity/8; c++){
       for (d = 1; d <=propagation_velacity/4; d++){

             count++;
          if( count==(propagation_velacity/15)*(propagation_velacity/10)){

    printf("Receiver receives a messages:--->%s",&a);
          }}}

   }
	}
   return 0;
}
