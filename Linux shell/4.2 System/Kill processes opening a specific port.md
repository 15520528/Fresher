# Kết thúc một process đang mở tại một port cụ thể
#!/bin/sh
```shell
sudo netstat -nlptu|grep -i "listen" |awk -v A="$1" '$7~A {print $7;}' | awk -F '/' {'print $1;'} |xargs sudo kill
```