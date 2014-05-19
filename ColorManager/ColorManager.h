//
//  ColorManager.h
//  ColorManager
//
//  Created by   颜风 on 14-5-15.
//  Copyright (c) 2014年 Shadow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ColorDictionary.h"

@class Rgb;

/// block别名,用于将文件内容转换为NSDictionary格式.
typedef NSDictionary * (^ConverterToDictionary)(NSString *path);

/// block别名,用于将NSDictionry对象写入到指定文件
typedef BOOL(^ConverterToFile)(NSDictionary * dict, NSString * path, BOOL flag);

/// 颜色代理别名,用于简化颜色代理对象的定义.
typedef id<ColorDictionary> ColorDictionaryDelegate;

/**
 *  管理颜色数据的类
 */
@interface ColorManager : NSObject
#pragma mark - 属性
@property (nonatomic, strong)ColorDictionaryDelegate delegate;//!< 委托,用于以名值对形式存储字典.
#pragma mark - 便利构造器
/**
 *  便利构造器,从一个属性列表文件读取数据创建新对象.
 *
 *  @param aDelegate 颜色代理
 *  @param path      文件路径
 *
 *  @return 一个ColorManager对象.
 */
+ (instancetype) colorManagerWithDelegate:(ColorDictionaryDelegate)aDelegate
                     contentOfFile:(NSString *)path;

/**
 *  便利构造器,使用指定的block,从任一类型的文件读取数据,创建新对象.
 *
 *  @param aDelegate 代理
 *  @param path      文件路径
 *  @param ctd       block,用于将任一文件类型中的数据转换为特定数据格式返回.
 *
 *  @return 一个ColorManager对象.
 */
+ (instancetype) colorManagerWithDelegate:(ColorDictionaryDelegate)aDelegate
                    contentOfFile:(NSString *)path
                    usingConverter:(ConverterToDictionary) ctd;

/**
 *  便利构造器,从一个字典中获取数据,创建新对象.
 *
 *  @param aDelegate 颜色代理
 *  @param dict      提供数据的字典
 *
 *  @return 一个ColorManager对象.
 */
+ (instancetype) colorManagerWithDelegate:(ColorDictionaryDelegate)aDelegate
                        dictionary:(NSDictionary *)dict;

#pragma mark - 初始化方法
/**
 *  便利初始化函数,从一个属性列表文件读取数据创建新对象.
 *
 *  @param aDelegate 颜色代理
 *  @param path      文件路径
 *
 *  @return 一个ColorManager对象.
 */
- (instancetype) initWithDelegate:(ColorDictionaryDelegate)aDelegate
                    contentOfFile:(NSString *)path;

/**
 *  便利构造器,使用指定的block,从任一类型的文件读取数据,创建新对象.
 *
 *  @param aDelegate 代理
 *  @param path      文件路径
 *  @param ctd       block,用于将任一文件类型中的数据转换为特定数据格式返回.
 *
 *  @return 一个ColorManager对象.
 */
- (instancetype) initWithDelegate:(ColorDictionaryDelegate)aDelegate
                    contentOfFile:(NSString *)path
                   usingConverter:(ConverterToDictionary) ctd;

/**
 *  便利构造器,从一个字典中获取数据,创建新对象.
 *
 *  @param aDelegate 颜色代理
 *  @param dict      提供数据的字典
 *
 *  @return 一个ColorManager对象.
 */
- (instancetype) initWithDelegate:(ColorDictionaryDelegate)aDelegate
                       dictionary:(NSDictionary *)dict;

# pragma mark - 实例方法
/**
 *  查询Rgb对象对应的颜色名.
 *
 *  @param aRgb 要查询器颜色名的Rgb对象.
 *
 *  @return 此Rgb对象对应的Rgb对象.
 */
- (NSString *)colorNameForRgb:(Rgb *)aRgb;

/**
 *  查询颜色名对应的Rgb对象.
 *
 *  @param aColorName 要查询器对应的Rgb对象的颜色名.
 *
 *  @return 此颜色名对应的Rgb对象.
 */
- (Rgb *)rgbForColorName:(NSString *)aColorName;

/**
 *  设置,更改Rgb对象的颜色名.如果传入的颜色名为nil,则会删除此Rgb对象相关的颜色数据.
 *
 *  @param aColorname 新的颜色名.
 *  @param aRgb       一个Rgb对象.
 */
- (void)setColorName:(NSString *)aColorname
              forRgb:(Rgb *)aRgb;

/**
 *  设置或者更改aClorName对应的Rgb对象;如果aRgb为nil,则直接删除aClorName相关的颜色数据.
 *
 *  @param aRgb       新的Rgb对象.
 *  @param aColorName 颜色名.
 */
- (void)setRgb:(Rgb *)aRgb
  forColorName:(NSString *)aColorName;

/**
 *  将颜色数据以NSDictionary格式写入指定的属性列表文件.
 *
 *  @param path 文件路径.
 *  @param flag YES,先将内容输出到一个临时文件,输出完成后,再重命名为目标文件;NO,直接输出到目标文件.后者,可能会损坏文件.
 *
 *  @return 成功返回YES,失败返回NO.
 */
- (BOOL)writeToFile:(NSString *)path
         atomically:(BOOL)flag;

/**
 *  使用指定的block,将颜色数据写入到任一类型的文件中.如果指定的block为nil或者block执行失败,则调用 writeToFile:atomically:方法.
 *
 *  @param flag YES,先将内容输出到一个临时文件,输出完成后,再重命名为目标文件;NO,直接输出到目标文件.后者,可能会损坏文件.
 *  @param ctf  block,函数将调用此方法,将数据写入到指定的文件中.
 *
 *  @return YES,成功;NO,失败.
 */
- (BOOL)writeToFile:(NSString *)path
         atomically:(BOOL)flag
     usingConverter:(ConverterToFile)ctf;

/**
 *  以字典形式返回所有字符串.
 *
 *  @return 含有所有颜色数据的字典,以颜色名为键,以Rgb数据为值.
 */
- (NSDictionary *)allColors;
@end
