# spa_lsb
## MacOS/Ubuntu
### Bước 1:
Mở terminal trỏ đến folder chứa code rồi chạy câu lệnh sau:
```
./compile_script.sh
```
### Bước 2:
**Ẩn tin**

Để ẩn tin vào ảnh chạy:
```
./program --encode <anh-muon-an-tin-vao> <noi-dung-can-an> <anh-sau-khi-an-tin>
```
*VD:*
```
./program --encode buombuom.bmp hello-la-hung-day result.bmp
```
**Giải mã**
```
./program --decode <anh-chua-tin> <file-ket-qua>
```
*VD:*
```
./program --decode result.bmp ketqua.txt 
```
## Window
### Bước 1:
Mua macbook hoặc cài ubuntu (linux)
### Bước 2:
Thực hiện tuần tự các bước ở mục MacOS/Ubuntu
