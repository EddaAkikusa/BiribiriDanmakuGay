比利比利弹幕基
----
目标是尽可能使用最低限度的外部依赖实现最简易的 B 站直播弹幕工具，优先目标是实现**抓取弹幕**和**读弹幕**的功能，未来会做 Direct2D + DirectWrite 渲染实时弹幕列表来供 OBS 抓取。

程序设计上只使用 C，没意外的话尽量只使用系统提供的 API，目前唯一例外是 Brotli 解码器需要第三方库。

在考虑用传统 Win32 API 只用来写界面，其他功能通过 Windows Runtime 来实现（包括网络通信、TTS、JSON 处理和 Deflate 数据解包）。

原则上源代码应该只有 4 个文件：

- `main.c`
- `res.rc`
- `resource.h`
- `manifest.xml`
