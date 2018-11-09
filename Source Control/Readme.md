## 1. Nội Dung
#### working tree và index
- Trên Git, những thư mục được đặt trong sự quản lý của Git mà mọi người đang thực hiện công việc trong thực tế được gọi là working tree.

![GitHub Logo](./images/index.png)

- Và trên Git, giữa repository và working tree tồn tại một nơi gọi là index. Index là nơi để chuẩn bị cho việc commit lên repository.
#### 1.1 Tạo repository
- Trước tiên hãy tạo thư mục tutorial ở nơi tùy ý trên máy. Để đặt 1 thư mục dưới sự quản lý của Git, sử dụng lệnh `init` để di chuyển đến thư mục đó. 

```
$ mkdir tutorial
$ cd tutorial
$ git init
```
#### 1.2 commit 1 file
- sử dụng lệnh `add <file>` để đăng ký sự theo giõi của git
 
    ```
    add hihi.txt
    ```
- có thể sử dụng `git add.` để add tất cả các file trong 
- file sau khi được add thì được đưa vào index và chuẩn bị để commit 
- Sử dụng `git commit -m "message"` để commit

    ```shell
    git commit -m "this is the first commit"
    ```
- Sử dụng lệnh `status` để kiểm tra trạng thái của working tree và index
    ```
    git status
    ```