# this is some code for visulizing the DFT process
# Maybe you need to download the SFML framework for the program


> ### 《算法导论》对于FFT的推导过程

> ### a、多项式系数表示法

>> #### 1、计算多项式的乘法
>>> ##### A = sum(Ai * pow(x , i)) , B = sum(Bi * pow(x , i)), i = 0 to N - 1
>>> ##### C = A * B = sum(Ci * pow(x , i)) , i = 0 to N - 2，按照多项式的乘法来计算的话会得到 2 * N - 2 阶的多项式，计算过程为卷积计算过程，时间复杂度为O(n^2)
>>> ##### 所以，计算多项式的乘法会有O(n^2)的时间复杂度


> ### b、多项式的点值表示
>> #### 1、多项式的点值表示法，一个N阶多项式可以由N个不同的点来唯一表示，证明很简单，采用秦九韶算法，系数表示到点值需要O(n)的时间复杂度
>> #### 2、使用点值表达式来计算多项式的乘积，即2中的问题。可以采用逐点计算来得到新多项式的值，如果是乘法，因为新多项式的阶数为2 * N - 2 ，所以点值表示的每一个多项式需要2 * N - 2 个点的值
>> #### 3、点值表示的一般多项式乘法 
>>> ##### 系数 -> 点值 O(n)
>>> ##### 点值的乘法 O(n)
>>> ##### 点值 -> 系数 O(n^2)
>> #### 总时间复杂度为O(n^2)

>> #### 可以看出，点值表示和系数表示的时间复杂度是一样的，都是O(n^2)的复杂度量级
>> #### 所以，只要能找到一个快速算法，实现系数与点值，和点值与系数的快速转换

>> #### 选取复数根，并采用FFT算法
>> #### 系数 -> 点值 O(nLogn)
>> #### 点值 -> 系数 O(nLogn)
>> #### 使得多项式乘法的计算事件复杂度降低为O(nLogn)

# FFT算法非递归解法
```
n = a.length  

for s = 1 to log(n)
    m = 2^s
    w_m = e^{2pi/m}
    for k = 0 to n - 1 by m
        w = 1
        for j = 0 to m / 2 - 1
            t = w * A[k + j + m / 2]
            u = A[k + j]
            A[k + j] = u + t
            A[k + j + m / 2] = u - t
            w = w * w_m
```

