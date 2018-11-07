### Liệt kê các file có kích thước lớn hơn 100K trong thư mục /home/username

## Ý tưởng
* 1. Sử dụng lệnh find tìm các file có kích thước lớn hơn 100K, và lưu vào biến $arr
* 2.  lấy input từ user
    * 1. nếu user nhập 'd' thì sử dụng lênh rm xóa file lưu trong biến $arr , và ghi danh sách files đã xóa vào logfile
    * 2. nếu user nhập 'c' thì dung lệnh tar để nén file 

```c
#!/bin/sh
cd /    // di chuyển về root
cd home     //di chuyển đến thư mục home
cd lap10547 //di chuyển vào thư mục user 
echo [+] found files:  
arr=$(find . -type f -size +100K)
echo $arr      //liệt kê các file tìm được
echo "[+] Would you like to delete or compress these files, press d (delete) or c (compress)?"
read opt // lấy input từ người dùng
if [ "$opt" = "d" ] //nếu người dung nhập 'd' thì xóa danh sách file tìm được, và xuất vào logfile
then
	rm -v $arr > logfile.txt 
    //thêm chỉ thị -v để biết được số file đã xóa
else
    //ngược lại người dùng nhập 'c' thì tiến hành nén files vào file có tên là a.tar.gz
	echo "compressed files"
	tar -czvf a.tar.gz $arr 
fi
```