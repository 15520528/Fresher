## Chấm dứt các process khớp với 1 patern, cụ thể là tên của process 
### ý tưởng
* 1. Sử dụng lệnh ps aux xuất ra thông tin chi tiết từng process trên hệ điều hành lúc này
* 2. Sự dụng awk để đọc tưng hàng và cột từ kết quả sau khi thực hiện lệnh ps aux. Sau đó, so khớp biến $11( là cột chứa tên process) với từng hàng kết quả, nếu hàng nào khớp thì in ra ID từng process
* 3. Sử dụng lệnh xargs để chuyển ID process khớp với patern  cho lệnh kill. lệnh kill lúc này sẽ kết thúc các process này

file killprocess.sh 

``` shell
#!/bin/sh
ps aux|awk -v A="$1" '$11~A {print $2}'| xargs kill 
```
Các chạy : Trên terminal ghõ ./killprocess.sh "tên process muốn terminate"

Ví dụ: ta nếu muốn terminate các process có tên là xlogo

![terminal1]
(./images/process.png)

