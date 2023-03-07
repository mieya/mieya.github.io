---
title: Typora+PicGo+Github搭建图床
date: 2023-03-06 21:49:50
categories: 博客
tags:
- Typora
- 图床
---



### 图床选择

图床是一个用于存储和管理图片的网站或服务。它可以允许用户上传、存储、管理和分享图片，并为用户生成图片的URL，这样用户可以在需要时将图片链接嵌入到其它网站或应用程序中，非常方便个人博客使用。

在将Markdown编辑器换成Typora后，我发现将Typora与PicGo结合起来，可以一键式将md文件里的图片上传图床并自动生成外链，非常方便。

<!--more-->

此前，我一直采用【路过图床】作为博客的图床，但仅是简单使用，再去了解后我才发现【路过图床】免费版的有这么多限制，比如：每小时限制上传50张图片，每天限制上传100张图片，而且免费版用户的存储容量貌似不过300M。而其它一些免费的图床不是跑路了就是限制太多，比如限制每小时上传的次数、单张图片不大于5MB等等。因此，最后我选择使用Github作为新的图床。

使用Github也有缺点，国内访问速度可能会比较慢，不过我们可以利用jsDelivr CDN加速访问，在Typora里设置好一键上传图片至PicGo，操作简单又高效。此外，使用Github和jsDelivr还不用担心用到一半跑路的问题，并且完全免费。



### 新建Github仓库

在Github中新建一个仓库，注意要将仓库设置为公开（public），因为使用 PicGo 访问私有仓库里的图片时，会生成带有 Token 的 URL。这个 Token 是有过期时间的，一旦过期就无法继续访问。

![image-20230306212028034](https://fastly.jsdelivr.net/gh/mieya/BlogImg/BLOG-IMG/image-20230306212028034.png)

仓库建好之后，在个人主页依次选择【Settings】-【Developer settings】-【Personal access tokens】- 【Tokens(classic)】，然后点击【Generate new token】。填写好描述，有效期Expiration可以选择永久，勾选【repo】，然后点击【Generate token】就会生成一个 Token。注意，这个 Token 只会显示一次，请务必先保存下来，或者等后面配置好 PicGo 后再关闭此网页。

### 配置PicGo

Token生成后就可以在PicGo里进行配置了，点击此处[下载PicGo](https://github.com/Molunerfinn/picgo/releases)，安装完毕后，进入并在左侧【图床设置】中找到【Github】图床配置。

![image-20230306212903776](https://fastly.jsdelivr.net/gh/mieya/BlogImg/BLOG-IMG/image-20230306212903776.png)

注意**设定分支名**改为【main】，因为GitHub 官方表示,从2020年10月1日起,在该平台上创建的所有新的源代码仓库将默认被命名为"main",而不是原先的"master"。**设定存储路径**可以为空，如果想将图片上传到仓库的指定目录下，可以填写目录名加/，比如我想将图片存放在BlogImg仓库下的BLOG-IMG文件夹中，则此处需设置为 BLOG-IMG/。

设置定义域名：

这里使用jsDelivr的CDN加速服务，上传图片成功后，PicGo会将自定义域名和上传的图片名拼接起来生成一个访问链接。

> 自定义域名格式：https://cdn.jsdelivr.net/gh/GitHub账户名/仓库名 
>
> 以我的格式为例：https://cdn.jsdelivr.net/gh/mieya/BlogImg

### 配置Typora

在Typora中依次选择【文件】-【偏好设置】-【图像】，做出如下图所示设置，最后点击验证图片上传选项，显示验证成功即可。

![image-20230306213619040](https://fastly.jsdelivr.net/gh/mieya/BlogImg/BLOG-IMG/image-20230306213619040.png)

之后在编写md文件时，只要在【格式】-【图像】中找到【上传所有本地图片】，即可将当前文件中的所有本地图片上传至Github仓库。

### 相关参考资料

[Github+jsDelivr+PicGo 打造稳定快速、高效免费图床_github 图床_ITBOB • 鲍勃的博客-CSDN博客](https://blog.csdn.net/qq_36759224/article/details/98058240)

[PicGo+GitHub 图床搭建 - Jinweidy - 博客园 (cnblogs.com)](https://www.cnblogs.com/wdysblog/p/16610733.html#1-绑定github图床)

