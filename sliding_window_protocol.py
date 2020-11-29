no_of_frames=[]
window=int(input("enter the window size:"))
frames=int(input("enter no of frames to be transmitted"))
print("the frame values are:")
for i in range (0,frames):
 fr=int(input())
 no_of_frames.append(fr)
print(no_of_frames)
for j in range (1,frames+1):
 if j%window == 0:
  print(no_of_frames[j-1])
  print("acknoledge message of the above frame sent is received by the sender ")
 else:
  print(no_of_frames[j-1])