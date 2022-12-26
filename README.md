# “你帮我助”软件开发（Final)
## 功能需求
1、物品有公共的信息（物品名称，物品说明，物品所在地址，联系人手机，邮箱）。为了便于管理和查询，物品可以分成不同的类别（例如食品、书籍、工具等），不同类别的物品可能有不同的属性（例如食品有保质期，数量；书籍有作者，出版社等）。

2、互帮互助系统有两种类型的用户：管理员和普通用户。
- 管理员可以设置新的物品类型（定义物品类型的名称和各个属性），修改物品类型。
- 普通用户在添加物品时先选择物品类型，然后再填入物品信息。普通用户搜寻物品时，需要先选择类型，再输入关键字，关键字可以再用户名称和说明中进行匹配。
- 普通用户需要注册（填入基本信息，包括住址，联系方式等），管理员批准后才能成为正式用户。

3、为了便于使用上述功能，软件需要提供GUI。
## 文档需求
需要提供一个文档：其中包括(1)用例模型；（2）针对用例画顺序图；（3）类图。
### 用例模型
![image](https://user-images.githubusercontent.com/114299322/209491527-38b899fc-9761-44f4-abf6-aa6aed0a0396.png)
### 类图
![image](https://user-images.githubusercontent.com/114299322/209491511-f50cdd6d-06f5-46bc-bc02-3f20ba55ab5b.png)
### 顺序图
- 普通用户添加物品顺序图

![image](https://user-images.githubusercontent.com/114299322/209491542-09316408-c79e-48a4-9a0b-420d95c71d5c.png)
- 普通用户查询物品顺序图

![image](https://user-images.githubusercontent.com/114299322/209491563-c7e4fa33-cfae-4c46-8888-f6e61c426cd6.png)
- 普通用户删除物品顺序图

![image](https://user-images.githubusercontent.com/114299322/209491583-a93d7d95-5513-4246-bff3-794e43ce3b09.png)
- 申请注册审批顺序图

![image](https://user-images.githubusercontent.com/114299322/209491598-6f3534db-9c12-45ff-a0b9-4a025844b589.png)
- 管理员操作物品顺序表

![image](https://user-images.githubusercontent.com/114299322/209491622-66418939-0516-4935-823d-9a2cbc97e61b.png)

因个人原因，管理员部分的功能尚未完全实现。
