import random
no_tr=0
nf=int(input("Enter no of frames :"))
N=int(input("Enter window size :"))
i=1
while(i<=nf):
    x=0
    for j in range(i,i+N):
        if(j<=nf):
            print("sent frame",j)
            no_tr=no_tr+1
    for j in range(i,i+N):
        if(j<=nf):
            flag=random.randint(0,2)%2
            if not flag:
                print("Acknowledgement for frame",j)
                x=x+1
            else :
                print("Frame",j,"not received")
                print("Retransmitting window")
                break
    i+=x
print("Total no of transmissions :" ,no_tr)