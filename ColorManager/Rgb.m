//
//  Rgb.m
//  ColorManager
//
//  Created by   颜风 on 14-5-15.
//  Copyright (c) 2014年 Shadow. All rights reserved.
//

#import "Rgb.h"

@implementation Rgb
#pragma mark - 属性
@synthesize red = _red; // 红
@synthesize green = _green; // 绿
@synthesize blue = _blue; // 蓝
#pragma mark - 便利构造器
+ (instancetype) rgbWithRed:(NSUInteger)red green:(NSUInteger)green blue:(NSUInteger)blue
{
    Rgb * temp = [[[self class] alloc] initWithRed:(NSUInteger)red green:(NSUInteger)green blue:(NSUInteger)blue];
    return temp;
}

+ (instancetype)rgbWithString:(NSString *)aString
{
    Rgb * temp;
    temp = [[[self class] alloc] initWithString:aString];
    return temp;
}

#pragma mark - 工具方法
+ (NSArray *) numberHexString:(NSString * )aHexString
                         step:(NSUInteger)step
{
    // 首先考虑字符串对象为nil的情况:直接返回nil
    if (nil == aHexString)
    {
        return nil;
    }
    
    // 先考虑step为0,将字符串整体解析为正整数.
    if (0 == step)
    {
        NSNumber * hexNumber = [[self class]numberHexString:aHexString];
        NSArray * result = @[hexNumber];
        
        return result;
    }
    
    // 分析将字符串分作多个十六进制字符串的情况.
    
    NSMutableArray * temp = [NSMutableArray arrayWithCapacity:42]; // 临时存储转换结果.
    
    NSUInteger i = 0;
    for(; i + step < aHexString.length; i += step)
    {
        // 将字符串转换为整数.
        NSString * tempHexString;
        tempHexString = [aHexString substringWithRange:NSMakeRange(i, step)];
        NSScanner * scanner = [NSScanner scannerWithString:tempHexString];
        unsigned long long longlongValue;
        [scanner scanHexLongLong:&longlongValue];
        
        //将整数转换为NSNumber,存储到数组中,并返回.
        NSNumber * hexNumber = [NSNumber numberWithLongLong:longlongValue];
        [temp addObject:hexNumber];
    }
    
    // 单独处理最后一个十六进制字符串块.
    if (i + step != aHexString.length -1)
    {
        // 将字符串转换为整数.
        NSScanner * scanner = [NSScanner scannerWithString:[aHexString substringFromIndex:i]];
        unsigned long long longlongValue;
        [scanner scanHexLongLong:&longlongValue];
        
        //将整数转换为NSNumber,存储到数组中,并返回.
        NSNumber * hexNumber = [NSNumber numberWithLongLong:longlongValue];
        [temp addObject:hexNumber];
    }
    
    // 将返回数据改为要求的类型,并返回.
    NSMutableArray * result;
    result = [NSMutableArray arrayWithArray:temp];
    
    return result;
}

+ (NSNumber *) numberHexString:(NSString *)aHexString
{
    // 为空,直接返回.
    if (nil == aHexString)
    {
        return nil;
    }
    
    NSScanner * scanner = [NSScanner scannerWithString:aHexString];
    unsigned long long longlongValue;
    [scanner scanHexLongLong:&longlongValue];
    
    //将整数转换为NSNumber,存储到数组中,并返回.
    NSNumber * hexNumber = [NSNumber numberWithLongLong:longlongValue];
    
    return hexNumber;
}

#pragma mark - 初始化函数
- (instancetype) initWithRed:(NSUInteger)red green:(NSUInteger)green blue:(NSUInteger)blue
{
    if (self = [super init])
    {
        self.red = red;
        self.green = green;
        self.blue = blue;
    }
    return self;
}

- (instancetype) initWithString:(NSString *)aString
{
    if (self = [super init])
    {
        // 借助工具函数,把十六进制字符串解析为NSNumber数组.
        NSArray * hexArray = [[self class] numberHexString:aString step:2];
        
        // 如果得不到三个十六进制数,就直接返回.
        if (3 != hexArray.count)
        {
            return nil;
        }
        
        self.red = [[hexArray objectAtIndex:0] integerValue];
        self.green = [[hexArray objectAtIndex:1] integerValue];
        self.blue = [[hexArray objectAtIndex:2] integerValue];
    }
    return self;
}

#pragma mark - 实例方法
- (BOOL) isEqualToRgb:(Rgb *)otherRgb
{
    // 是否为同一对象?
    if (self == otherRgb)
    {
        return YES;
    }
    
    // 是否为空?是不是同一类对象?
    if ( nil == otherRgb || NO == [otherRgb isKindOfClass:[self class]])
    {
        return NO;
    }
    
    // 属性是否相等?
    if (self.red == otherRgb.red &&  self.green == otherRgb.green && self.blue == otherRgb.blue)
    {
        return YES;
    }
    
    return NO;
}

- (NSString *)stringRgb:(BOOL)flag
{
    NSString * result; // 存储要返回的字符串
    
    // 假定你想获得0X形式的十六进制字符串.
    result = [NSString stringWithFormat:@"%.2lX%.2lX%.2lX", self.red, self.green, self.blue];
    
    // 你还是想要0x形式的十六进制字符串?
    if(NO == flag)
    {
        result = [NSString stringWithFormat:@"%lx%lx%lx", self.red, self.green, self.blue];
    }
    
    return result;
}

- (void)setRed:(NSUInteger)red
{
    if (red > 255)
    {
        red = 255;
    }
    _red = red;
}

- (void)setGreen:(NSUInteger)green
{
    if (green > 255)
    {
        green = 255;
    }
    _green = green;
}

- (void)setBlue:(NSUInteger)blue
{
    if (blue > 255)
    {
        blue = 255;
    }
    _blue = blue;
}

@end
