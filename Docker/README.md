### Định nghĩa
- Docker là một open platform cung cấp cho người sử dụng những công cụ và service để người sử dụng có thể đóng gói và chạy chương trình của mình trên các môi trường khác nhau một cách nhanh nhất.
### Các thành phần của docker
1. Image 
-    Là một gói mà chứa mọi thứ cần thiết để chạy một ưngs dụng, runtime, libraries, biến môi trường, file cấu hình
    
- Từ các image này, bạn sẽ dùng nó để tạo ra các container.
2. Container
- Tương tự như máy ảo, một container được tạo bằng chạy một image, 
- Container chạy trên linux và chia s    ẻ kernel của máy với các c    ontainer khác, nó sử dụng ít bộ nhớ hơn so với các máy ảo. Khi nào cần bộ nhớ thì sẽ được kernel cấp thêm
- Ngược lạ với máy ảo, máy ảo cần được cấp phát tài nguyên như ram, bộ nhớ và làm chậm máy. Nếu máy ảo không được sử dụng thì nhưng tài nguyên trên cũng không được sử dụng theo (hao phí)
### Các lệnh trên docker
-  `docker info ` Xem chi tiết về docker
-  `docker image ls` Liệt kê  danh sách các image 
- `docker ps -a` liệt kê danh sách các container đã được khởi tạo
- ` sudo docker run -it <name image> /bin/bash` chạy một container trên chế độ interactive mode
- `docker history ImageID ` Xem các command được chạy cho một image
- 