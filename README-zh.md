# Riru - HookManagedProfile

一个 Hook 掉位于 ``android.os.UserManagaer`` 的函数 isManagedProfile() 模块，用于解除系统对工作资料的访问限制。

## 为什么要发明这个

当我使用 [Island](https://play.google.com/store/apps/details?id=com.oasisfeng.island)（一个基于工作资料的双开应用）时，我希望一些应用能够访问系统通知。然而系统冷漠的扔下了这么一个吐司：
> 工作资料内的应用无法访问通知

WTF?!

于是，这个用于解除该限制的模块就诞生了。理论上也能解除其它通过调用 ``isManagedProfile()`` 限制应用功能的程序。

## 兼容性

只在**类原生**系统上测试过（例如 Oxygen OS）。重度魔改系统（如 MIUI、Flyme 等）请自行测试兼容性。

**无论如何，建议你在刷写该模块前做好备份措施，以避免在无法进入系统的情况下束手无措**

## 副作用

还未测试出来。如果有，我会尽快贴在这里。:)

