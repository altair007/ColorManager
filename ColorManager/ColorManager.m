//
//  ColorManager.m
//  ColorManager
//
//  Created by   颜风 on 14-5-15.
//  Copyright (c) 2014年 Shadow. All rights reserved.
//

#import "ColorManager.h"
#import "Rgb.h"

@implementation ColorManager
#pragma mark - 属性
@synthesize delegate = _delegate;

#pragma mark - 便利构造器

+ (instancetype) colorManagerWithDelegate:(ColorDictionaryDelegate)aDelegate
                     contentOfFile:(NSString *)path
{
    id temp = [[[self class] alloc]initWithDelegate:aDelegate contentOfFile:path];
    return temp;
}

+ (instancetype) colorManagerWithDelegate:(ColorDictionaryDelegate)aDelegate
                     contentOfFile:(NSString *)path
                    usingConverter:(ConverterToDictionary) ctd
{
    id temp = [[[self class] alloc]initWithDelegate:aDelegate contentOfFile:path usingConverter:ctd];
    return temp;
}

+ (instancetype) colorManagerWithDelegate:(ColorDictionaryDelegate)aDelegate
                        dictionary:(NSDictionary *)dict
{
    id temp = [[[self class] alloc]initWithDelegate:aDelegate dictionary:dict];
    return temp;
}

#pragma mark - 初始化方法

- (instancetype) initWithDelegate:(ColorDictionaryDelegate)aDelegate
                    contentOfFile:(NSString *)path
{
    if(self = [super init])
    {
        // 设置代理
        self.delegate = aDelegate;
        NSDictionary * dict;
        dict = [NSDictionary dictionaryWithContentsOfFile:path];
        [dict enumerateKeysAndObjectsUsingBlock:^(NSString * aColorName, id obj, BOOL *stop)
         {
             // 字典中存储的可能是NSString对象,也可能是Rgb对象.
             if([obj isKindOfClass:[NSString class]])
             {
                 // obj是一个十六进制字符串,转成Rgb对象.
                 obj = [Rgb rgbWithString:obj];
             }
             [self.delegate setRgb:obj forColorName:aColorName];
         }];    }
    
    return  self;
}

- (instancetype) initWithDelegate:(ColorDictionaryDelegate)aDelegate
                    contentOfFile:(NSString *)path
                    usingConverter:(ConverterToDictionary) ctd
{
    NSDictionary * dict;
    
    // 若block为nil或者block返回nil,则使用类默认的的初始化方法.
    if (nil != ctd)
    {
        dict = ctd(path);
    }
    
    if(nil != dict)
    {
        return [self initWithDelegate:aDelegate contentOfFile:path];
    }
    
    if(self = [super init])
    {
        self.delegate = aDelegate;
        [dict enumerateKeysAndObjectsUsingBlock:^(NSString * aColorName, id obj, BOOL *stop)
         {
             // 字典中存储的可能是NSString对象,也可能是Rgb对象.
             if([obj isKindOfClass:[NSString class]])
             {
                 // obj是一个十六进制字符串,转成Rgb对象.
                 obj = [Rgb rgbWithString:obj];
             }
             [self.delegate setRgb:obj forColorName:aColorName];
         }];
    }
    return  self;
}

- (instancetype) initWithDelegate:(ColorDictionaryDelegate)aDelegate
                       dictionary:(NSDictionary *)dict
{
    if (self = [super init])
    {
        self.delegate = aDelegate;
        [dict enumerateKeysAndObjectsUsingBlock:^(NSString * aColorName, id obj, BOOL *stop)
         {
             // 字典中存储的可能是NSString对象,也可能是Rgb对象.
             if([obj isKindOfClass:[NSString class]])
             {
                 // obj是一个十六进制字符串,转成Rgb对象.
                 obj = [Rgb rgbWithString:obj];
             }
             [self.delegate setRgb:obj forColorName:aColorName];
         }];
    }
    return  self;
}

# pragma mark - 实例方法

- (NSString *)colorNameForRgb:(Rgb *)aRgb
{
    NSString * colorName = [self.delegate colorNameForRgb:aRgb];
    return colorName;
}

- (Rgb *)rgbForColorName:(NSString *)aColorName
{
    Rgb * rgb = [self.delegate rgbForColorName:aColorName];
    return rgb;
}

- (void)setColorName:(NSString *)aColorname
              forRgb:(Rgb *)aRgb
{
    [self.delegate setColorName:aColorname forRgb:aRgb];
}

- (void)setRgb:(Rgb *)aRgb
  forColorName:(NSString *)aColorName
{
    [self.delegate setRgb:aRgb forColorName:aColorName];
}


- (BOOL)writeToFile:(NSString *)path
         atomically:(BOOL)flag
{
    // 获取颜色字典
    NSDictionary * ColorDict = [self allColors];
    
    // 将颜色字典中的Rgb转为字符串,并存储到一个新的字典中.
    NSMutableDictionary * dict = [NSMutableDictionary dictionaryWithCapacity:ColorDict.count];
    [ColorDict enumerateKeysAndObjectsUsingBlock:^(NSString * colorName, Rgb * rgb, BOOL *stop)
    {
        [dict setObject:[rgb stringRgb:YES] forKey:colorName];
    }];
    
    // 现在新的颜色字典中全部为属性列表类对象,可以直接调用方法将数据写入实例列表文件了
    BOOL result = [dict writeToFile:path atomically:flag];
    return result;
}

- (BOOL)writeToFile:(NSString *)path
         atomically:(BOOL)flag
     usingConverter:(ConverterToFile)ctf
{
    BOOL result = NO;// 存储结果.
    
    NSDictionary * dict = [self allColors];// 所有颜色数据
    
    // 先让自定义block试一下.
    if(nil != ctf)
    {
        result = ctf(dict, path, flag);
    }
    
    // 自定义的block完成任务了吗?
    if(result == NO)
    {
        result = [self writeToFile:path atomically:flag];
    }
    
    // 返回结果.
    return result;
}

- (NSDictionary *)allColors
{
    NSDictionary * dict = [self.delegate allColors];
    return dict;
}
@end
