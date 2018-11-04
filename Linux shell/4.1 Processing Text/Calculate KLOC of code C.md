## Đếm số lượng dòng code trong c/c++
> find  -regex  ".*\.\(cpp\|c\)" -print0|xargs -0 wc -l

### ý tưởng
Sử dụng lệnh find kết hợp với regular expression tìm các file có đuôi là .cpp hoặc .c, sau đó dùng xargs chuyển results sang cho lệnh wc để  đọc tưng file trong results , -l để in ra số dòng thay vì in ra toàn bộ dòng, số từ, số bytes