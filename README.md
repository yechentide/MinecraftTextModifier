# MinecraftTextModifier

## 说明

这是一个用来修正Minecraft Bedrock Edition的游戏文本的程序

## 用法

在MinecraftTextModifier可执行程序旁边，新建一个src文件夹
src里面必须要有zh_CN.lang文件
按需求放入rightText.txt，zh_CN_new.lang文件

├── MinecraftTextModifier
└── src
    ├── rightText.txt
    ├── zh_CN.lang
    └── zh_CN_new.lang

* zh_CN.lang
当前使用的语言文本，必须。

* rightText.txt
需要修正的文本。

* zh_CN_new.lang
新版本的语言文本。

## rightText.txt的写法
以`#`开头的都算是注释(`#`的个数不限)
写法参照zh_CN.lang
```
container.repair.expensive=修不了了，废了！
item.turtle_helmet.name=忍者神龟帽
potion.turtleMaster.postfix=忍者神龟药水
```

## 工作原理

zh_CN.lang文件是必须的，这是因为当程序开始运行，它会读取zh_CN.lang文件的内容，并分类保存到DataManager类的instance里

当按需求读取rightText.txt或者zh_CN_new.lang文件，也同样会生成DataManager类的instance

这个小程序很简单，就是单纯的对比数据。

* 当你要用rightText.txt里的数据更新文本时，将会用rightText.txt的数据覆盖原来的。如果该数据不存在于原来的文本里，则会无视该数据
* 当你要对比zh_CN_new.lang来得出新增内容时，则是对比两个instance的不同部分

