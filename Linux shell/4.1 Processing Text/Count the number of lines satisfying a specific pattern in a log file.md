## Đếm số lượng dòng thỏa mãn một pattern trong một file
> cat filePath|grep "patern"|wc -l

### ý tưởng
Dùng cat đọc nội dung từ filepath, kết hợp sử dụng grep "patern" để tìm các dòng text chứa patern, sau đó dùng wc -l để đếm số dòng chứa patern

* cat : đọc nội dung từ filePath
* file path: đường dẫn đến file text
* grep "patern" : định nghĩa 1 patern cần so khớp
* wc -l : Xuất ra số dòng 