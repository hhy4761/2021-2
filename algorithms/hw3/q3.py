def find_pal(str,cur,arr,dp):
    # print(cur)

    if cur==len(str):
        for ii in range(len(arr)):
            print(arr[ii],end='')
            print(' ',end='')
        print('\n',end='')
        return 0

    for i in range(cur,len(str)) :
        if check_DP(str,cur,i,dp):
            arr.append(str[cur:i+1])
            find_pal(str,i+1,arr,dp)
            arr.pop()


def check_DP(str,start,end,dp):
    # print(dp)
    # print(str, start, end)

    if dp[start][end]!=False: 
        return dp[start][end]
    
    else:
        while start<end:
            # print("str[start]:" + str[start])
            # print("str[end]:" + str[end])
            if str[start]!=str[end]: 
                dp[start][end] = False
                return dp[start][end]
            start+=1
            end-=1
        
        dp[start][end] = True
        return dp[start][end]

arr = []
str = input()
dp = [[False for i in range(len(str))] for j in range((len(str)))]
find_pal(str,0,arr,dp)