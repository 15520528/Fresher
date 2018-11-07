# Tìm các file thông qua regular expresion và xóa chúng
> find -name  patern -print0|xargs -0 rm

## ý tưởng
Sử dụng lệnh find tìm tên các file khớp với patern. Sau đó dùng lệnh xargs chuyển results cho lệnh rm, lệnh rm sẽ xóa lần lần lượt tên các file được trả về 
