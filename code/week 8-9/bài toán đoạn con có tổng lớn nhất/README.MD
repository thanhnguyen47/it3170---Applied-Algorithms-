### Bài toán đoạn con có tổng lớn nhất trong mảng
- Dùng phương pháp chia để trị trong tuần trước ==> O(Nlog(N)) 
- Dùng phương pháp quy hoạch động 

#### Phương pháp giải bài toán bằng quy hoạch động
1. Bước đầu tiên là tìm công thức quy hoạch động 
    - Gọi MaxSum(i) là trọng số của đoạn có trọng số lớn nhất trong 1..i
    - Cơ sở: MaxSum(1) = max(0, A[1])
    - Chuyển quy nạp: MaxSum(i) = max(A[i], MaxSum(i - 1))
    - Vậy kết quả cuối cùng là max của MaxSum(i) với i = 1..n

- Ví dụ
7
-16 7 -3 0 -1 5 -4