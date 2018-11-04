# Basic linux

## làm việc với command
man command: hiển thị thông tin về lệnh 

whatis command: hiển thị mô tả ngắn về lệnh

> alias ' các lệnh '

> alias name ='string'

> unlias command : xóa alias
> alias : list alias trong eviroment


<span style="color:red " >Pwd </span>: trả về đương dẫn

## Ls
ls -a : xem tất cả file, cả file ẩn

ls -l : hiển thị chi tiết file trong 1 thư mục

 ls -t : sắp xếp theo time

## file 
Xác định kiểu của 1 file

## less filename
xem nội dung 1 file




xargs  kết hợp rm xóa 1 danh sách các file trong 1 file 

> < file : Đọc nội dung 1 file

> \>file : ghi nội dung 1 file : 

realpath file : duong dan tuyet doi den 1 file
ls -d "$PWD"/*  : liet ke realpath trong 1 folder
> sudo : SuperUserDo

> df: space in each partition

> du filename : size ổ đĩa cấp phát cho tưng fike trong 1 thư mục

# Nén, giải nén file
tar 
zip

> chmod +x : cấp quyền chạy 1 ứng dụng

Ctrl C : stop any command in terminal

Ctrol Z:  force to stop it

> Bash: Bourne-Again SHel

# IO redirection

## 1. Redirecting Standard Output
    stdout: kết quả trả về 1 lệnh được lưu giữ trong đây
    stderr: thông tin trạng thái trả về  của lênh được lưu trong đây
    Nếu muốn chuyển kết quả trả về của một lệnh vào 1 file bất kì sử dụng cú phát bên dưới, sau khi sử dụng nếu results không bị lỗi, thì destinationFile sẽ reoverrite kết quả từ results. Tuy nhiên nếu lệnh thực biện bị lỗi thì destination file sẽ rỗng, do lệnh đó sẽ k gửi thông tin error về stdout mà gửi về stderr.
    
> command1 > destinationFile
    
    Làm rỗng 1 file 
   > ls-output.txt

    Để append ouput vào 1 file sủ dụng 
>  ls -l /usr/bin >> ls-output.txt
## 2. Redirecting Standard Error
> ls -l /usr/bin > ls-output.txt

## 3. Redirecting Standard Output And Standard Error To One File
    old version shell
> ls -l /bin/usr > ls-output.txt 2>&1

    new 
>  ls -l /bin/usr &> ls-output.txt

## 4.Disposing Of Unwanted Output
> ls -l /bin/usr 2> /dev/null

## 5. Pinelines
### wc :
    in ra số dòng , số từ, số bytes trong 1 file
> wc ls-output.txt

    Trong 1 số trường hợp nếu muốn chỉ in ra số dòng thì sử dụng lệnh
> ls /bin /usr/bin | sort | uniq | wc -l
###     grep:
    Lệnh này được dùng để tìm ra các dòng khớp với textpattern trong 1 file 
> grep [file]

    Nếu muốn bỏ qua so khớp chữ thường hoặc hoa thì thêm -i sau grep

> grep -i

### head/tails - print first/last file
    Lấy ra 5 dòng đầu từ output
> head -n 5 ls-output.txt

    Lấy ra 5 dòng cuối từ output

>  tail -n 5 ls-output.txt


