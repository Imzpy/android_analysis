#pragma once

#define IsBit64  __x86_64__ ||  __arm64__  || __aarch64__
#define IsBit32  __i386__ ||  __arm__
#define IsArm64  __arm64__  || __aarch64__
#define IsArm32  __arm__
#define IsX86_64  __x86_64__
#define IsX86_32  __i386__
#define IsX86 __x86_64__||__i386__
#define IsArm __arm__||__arm64__||__aarch64__

