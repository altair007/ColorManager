//
//  ColorDictionary.m
//  ColorManager
//
//  Created by   颜风 on 14-5-16.
//  Copyright (c) 2014年 Shadow. All rights reserved.
//

#import "ColorDictionary.h"
#import "Rgb.h"

@implementation ColorDictionary
#pragma mark - 属性
@synthesize dict = _dict;
#pragma mark - 便利构造函数
+(instancetype)colorDictionary
{
    id  temp = [[[self class] alloc]init];
    return temp;
}
#pragma mark - 初始化
-(instancetype)init
{
    if (self = [super init])
    {
        self.dict = [NSMutableDictionary dictionaryWithCapacity:42];
    }
    return self;
}

#pragma mark - ColorDictionary协议相关方法

- (NSString *)colorNameForRgb:(Rgb *)aRgb
{
    __block NSString * colorName;
    [self.dict enumerateKeysAndObjectsUsingBlock:^(NSString * key, Rgb * obj, BOOL *stop)
    {
        if ([aRgb isEqualToRgb:obj])
        {
            colorName = key;
            *stop = YES;
        }
    }];
    return colorName;
}

- (Rgb *)rgbForColorName:(NSString *)aColorName
{
    Rgb * rgb;
    rgb = [self.dict objectForKey:aColorName];
    return rgb;
}

- (void)setColorName:(NSString *)aColorname
              forRgb:(Rgb *)aRgb
{
    // 如果Rgb为nil,则直接返回.
    if (nil == aRgb)
    {
        return;
    }
    
    __block NSString * colorName; // 存储aRgb在字典中对应的键.
    
    // 快速枚举,寻找aRgb在字典中对应的键
    [self.dict enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop)
     {
         if ([obj isEqualToRgb:aRgb])
         {
             colorName = key;
             *stop = YES;
         }
     }];
    
    // aRgb在字典中无对应键.
    if (nil == colorName)
    {
        if (nil == aColorname)
        {
            return;
        }
        
        [self.dict setObject:aRgb forKey:aColorname];
        return;
    }
    
    // 说明aRgb在字典中有对应的键.
    if (nil == aColorname)
    {
        // 传入的颜色名为nil,说明要删除此aRgb关联的颜色数据.
        [self.dict removeObjectForKey:colorName];
        return;
    }
    
    // 更改aRgb对应的键.
    if ([aColorname isEqualToString:colorName])
    {
        return;
    }
    
    [self.dict removeObjectForKey:colorName];
    [self.dict setObject:aRgb forKey:aColorname];
}

- (void)setRgb:(Rgb *)aRgb
  forColorName:(NSString *)aColorName
{
    if (nil == aColorName)
    {
        return;
    }
    
    // 是要删除相关颜色数据吗?
    if (nil == aRgb)
    {
        [self.dict removeObjectForKey:aColorName];
        return;
    }
    
    // 新增或者更改.
    [self.dict setObject:aRgb forKey:aColorName];
}

- (NSDictionary *)allColors
{
    NSDictionary * dict;
    dict = [NSDictionary dictionaryWithDictionary:self.dict];
    return dict;
}
@end
