# GuiLite - 最小UI框架
- [功能介绍](#功能介绍)
- [实例程序](#实例程序)
- [开发文档](#开发文档)
- [学习方法](#学习方法)
- [视频链接](#视频链接)
- [致谢](#致谢)
***
## GuiLite是什么鬼？
- GuiLite（超轻量UI框架）是5千行代码的**全平台UI框架**，可以完美运行在iOS，Android，Windows（包含VR），Mac，和**市面所有的 ARM Linux物联网终端设备**上。
- GuiLite与操作系统无关，甚至也可以运行在无OS的单片机环境。
- GuiLite可以嵌入在iOS、Android、MFC、QT等其他UI系统中，让你的界面集百家之长，又不失个性。
- GuiLite鼓励混合编程，开发者可以用GuiLite接管UI部分，用Swift，Java，Go，C#，Python开发业务部分。

相比QT、MFC，GuiLite不预设开发者的使用场景，不在具体功能上，大包大揽；用框架的简洁，换取开发的自由；GuiLite在图形绘制上面，力图一步到位，运行效率感人。

## 为什么开发GuiLite？如何使用？
- 任何UI框架都不是为你我而生的，只有掌握核心原理，对其深度定制，才能真正掌握自己的命运！因此，我们开发了GuiLite，希望用这5千行代码揭示UI的核心原理和定制方法。
- 我们不推荐开发者全盘使用GuiLite；鼓励开发者在吃透代码后，根据自身业务特点，修改出更加丰富、个性的界面；或者发展出适合自己的UI框架。
- 为了聚焦UI核心原理，GuiLite会一直保持单片机的代码体量。

## 新功能：在单片机上运行“波形/粒子”效果 -- HelloWave + HelloParticle
![HelloWave](doc/HelloWave.gif)&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;![HelloParticle](doc/HelloParticle.gif)
- 单片机硬件配置：STM32F103ZET6(512K ROM，64K RAM) + 240*320 16位TFT屏
- 单片机软件配置：无操作系统 + GuiLite
- Hello Wave 仅有[100+行代码](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloWave/UIcode/UIcode.cpp)，用于向开发者展示：如何使用GuiLite进行“波形”效果的开发。
- Hello Particle 仅有[100-行代码](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloParticle/UIcode/UIcode.cpp)，用于向开发者展示：如何使用GuiLite进行“粒子”效果的开发。
- [1分钟“无痛”移植到任意单片机平台？](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloWave/README.md#How-to-port-on-any-MCU-)
- 该实例亦可支持Windows和Linux平台

## 功能介绍
### 卓越的跨平台能力
在Mac, iOS下的运行效果:

![Mac](doc/Mac.gif) ![iOS](doc/Ios.landscape.gif)

在Android，嵌入式ARM Linux下的运行效果:

![Android](doc/Android.gif) ![Linux](doc/Linux.gif)

在Windows混合现实，及单片机下的运行效果:

![Win MR](doc/WinMR.gif) ![MCU](doc/MCU.gif)

### 万国语和墙纸
- 墙纸：
![unicode](doc/wallpaper.jpg)

- 万国语(unicode)：
![unicode](doc/unicode.jpg)

- [如何制作多种文字/位图资源?](https://github.com/idea4good/GuiLiteToolkit)

### “换肤”功能
![multi-theme](doc/multi-theme.png)

[如何“换肤”？](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HostMonitor/SampleCode/source/resource/resource.cpp)

### 自我监控
- **上报“编译/运行”情况至“云端”：**

![BuildInfo](doc/BuildInfo.png)

- **同步“本地数据”至“云端”：**

![DataOnCloud](doc/data_on_cloud.png)

## 实例程序
GuiLite只是一个框架，本身并不能生成UI。为了能够展示如何用GuiLite开发App，我们提供了一些实例程序给大家参考。
- 点击[这里](https://gitee.com/idea4good/GuiLiteSamples)预览UI效果。
- 实例程序的功能说明：

| 实例名称 | 支持的平台 | 功能简介 | 编译方法 | 难度 |
| --- | --- | --- | --- | --- |
| HelloGuiLite | Windows, Linux | 初始化GuiLite，加载资源，布局界面元素，按钮响应 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloGuiLite/README.md) | 初级 |
| HelloFont | Windows, Linux | 显示多种语言（不限：中、英文） | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloFont/README.md) | 初级 |
| HelloAnimation | Windows, Linux | 动画的应用 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloAnimation/README.md) | 初级 |
| HelloParticle | Windows, Linux, STM32F103, STM32F429 | 粒子效果的应用 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloParticle/README.md) | 初级 |
| HelloSlide | Windows, Linux | 滑屏界面的应用 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloSlide/README.md) | 中级 |
| HelloWave | Windows, Linux, STM32F103, STM32F429 | 波形控件的应用 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HelloWave/README.md) | 中级 |
| HostMonitor | iOS, Mac, Android, Windows, Linux | 创建复杂界面，扩展自定义控件，适配全平台 | [编译/运行](https://gitee.com/idea4good/GuiLiteSamples/blob/master/HostMonitor/README.md) | 高级 |

## 开发文档
- [如何编译?](doc/HowToBuild.md)
- [设计原理](doc/CodeWalkthrough-cn.md)
- [UML示意图](doc/UML.md)
- [如何布局UI?](doc/HowLayoutWork.md)
- [如何传递消息?](doc/HowMessageWork.md)

## 学习方法
1. **外围** - 成功编译GuiLite库
2. **前戏** - 成功运行HelloXXX实例程序
3. **交流** - 研读/修改100+行的`HelloXXX/UIcode/UIcode.cpp`源代码
4. **深交** - 研读`gui`目录下的代码
5. **攻核** - 研读`core`目录下的代码
6. **分家** - 丰富，扩展自己的UI功能

## 视频链接:
- [GuiLite简介](https://v.youku.com/v_show/id_XMzA5NTMzMTYyOA)
- [3D GuiLite](https://v.youku.com/v_show/id_XMzYxNTE3MTI0MA)
- [GuiLite + 单片机](https://v.youku.com/v_show/id_XNDAwNzM5MTM3Ng)

## GitHub链接
[GitHub链接](https://github.com/idea4good/GuiLite)

## 致谢
### 感谢开发者群的所有同学，是你们塑造了今天的GuiLite！也欢迎新的大神/小白加入我们。
![QQ group: 527251257](doc/qq.group.jpg)
### 感谢来自码云用户的捐赠，您的每一分钱都会用来帮助急需帮助的中国儿童或家庭。

