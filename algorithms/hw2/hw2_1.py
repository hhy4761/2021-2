fread = open("hw2_input1.txt",'rt')
fwrite = open("hw2_output1.txt","wt") 

for i in range(4):
    if i == 0:
        fread = open("hw2_input1.txt",'rt')
        fwrite = open("hw2_output1.txt","wt") 
    elif i ==1:
        fread = open("hw2_input2.txt",'rt')
        fwrite = open("hw2_output2.txt","wt") 
    elif i ==2:
        fread = open("hw2_input3.txt",'rt')
        fwrite = open("hw2_output3.txt","wt")
    elif i ==3:
        fread = open("hw2_input4.txt",'rt')
        fwrite = open("hw2_output4.txt","wt")  

    nums = []

    while True:
        line = fread.readline()
        if line =='':
            break
        if 'k' in line:
            line.strip()
            k = int(line.split()[1])
        else:
            nums.append(int(line))  

    hashtable = dict()
    ans = []

    for num in nums:
        if num in hashtable:
            hashtable[num] +=1
        else:
            hashtable[num] = 1

    for key in hashtable:
        if k-key in hashtable:
            if k-key == key and key not in ans:
                ans.append(key)
                ans.append(k-key)
            elif k-key != key and key not in ans:
                ans.append(key)
                ans.append(k-key)

    for i in range(len(ans)):
        fwrite.write(str(ans[i])+" ")
        if i%2 != 0:
            fwrite.write("\n")
    fread.close()
    fwrite.close()