//
//  ColorManager.h
//  ColorManager
//
//  Created by   颜风 on 14-5-15.
//  Copyright (c) 2014年 Shadow. All rights reserved.
//

/*!
 * @class ColorManager
 * 颜色管理,用于颜色英文名对应颜色RGB值的快速查询和修改.
 */
#import <Foundation/Foundation.h>
#import "ColorDictionary.h"

@class Rgb; // RGB值类,用于以RGB格式存储RGB值.

// block别名,用于将文件内容转换为NSDictionary格式
typedef NSDictionary * (^ConverterToDictionary)(NSString *path);
// block别名,用于将NSDictionry对象写入到指定文件
typedef BOOL(^ConverterToFile)(NSDictionary * dict, NSString * path, BOOL flag);
// 颜色词典代理别名
typedef id<ColorDictionary> ColorDictionaryDelegate;

@interface ColorManager : NSObject
#pragma mark - 属性
@property (nonatomic, strong)ColorDictionaryDelegate delegate;// 委托,用于以名值对形式存储字典.
#pragma mark - 便利构造器
/*!
 * @method colorManagerWithContentsOfFil:
 * 从一个以字典格式存储的.plist属性列表文件读取数据,进行初始化,以key为颜色的名称,以value表示颜色的RGB的十六进制字符串.
 * 文件后缀不必是.plist;如果.plist文件不是以字典格式存储,将返回nil.
 */
+ (instancetype) colorManagerWithDelegate:(ColorDictionaryDelegate)aDelegate
                     contentOfFile:(NSString *)path;

/*!
 * @method colorManagerWithContentsOfFil:usingConverter:
 * 使用指定的工具函数,从文件读取数据,进行初始化.
 */
+ (instancetype) colorManagerWithDelegate:(ColorDictionaryDelegate)aDelegate
                    contentOfFile:(NSString *)path
                    usingConverter:(ConverterToDictionary) ctd;

/*!
 * @method colorManagerWithDictionary:
 * 用一个NSDictionary对象初始化,以key为颜色的名称,以value为颜色的RGB值或者一个存储rgb数据的十六进制字符串.
 */
+ (instancetype) colorManagerWithDelegate:(ColorDictionaryDelegate)aDelegate
                        dictionary:(NSDictionary *)dict;

#pragma mark - 初始化方法
/*!
 * @method initWithContentsOfFil:
 * 从一个以字典格式存储的.plist属性列表文件读取数据,进行初始化,以key为颜色的名称,以value为表示颜色的RGB的十六进制字符串.
 * 文件后缀不必是.plist;如果.plist文件不是以字典格式存储,将返回nil.
 */
- (instancetype) initWithDelegate:(ColorDictionaryDelegate)aDelegate
                    contentOfFile:(NSString *)path;

/*!
 * @method initWithContentsOfFil:usingConverter:
 * 使用指定的工具函数,从文件读取数据,进行初始化.
 */
- (instancetype) initWithDelegate:(ColorDictionaryDelegate)aDelegate
                    contentOfFile:(NSString *)path
                   usingConverter:(ConverterToDictionary) ctd;

/*!
 * @method initWithDictionary:
 * 用一个NSDictionary对象初始化,以key为颜色的名称,以value为颜色的RGB对象或者一个存储rgb数据的十六进制字符串.
 */
- (instancetype) initWithDelegate:(ColorDictionaryDelegate)aDelegate
                       dictionary:(NSDictionary *)dict;

# pragma mark - 实例方法
/*!
 * @method colorNameForRgb:
 * 查询rgb值对应的颜色名.
 */
- (NSString *)colorNameForRgb:(Rgb *)aRgb;

/*!
 * @method rgbForColorName:
 * 查询颜色名对应的RGB值.
 */
- (Rgb *)rgbForColorName:(NSString *)aColorName;

/*!
 * @method setColorName:forRgb:
 * 更改RGB值对应的颜色名.如果RGB值不存在,则直接添加.设置为nil,则会删除相关的颜色对象.
 */
- (void)setColorName:(NSString *)aColorname
              forRgb:(Rgb *)aRgb;

/*!
 * @method setRgb:forColorName:
 * 更改颜色名对应的RGB值.如果颜色名不存在,则直接添加.设置为nil,则会删除相关的颜色对象.
 */
- (void)setRgb:(Rgb *)aRgb
  forColorName:(NSString *)aColorName;

/*!
 * @method writeToFile:atomically:
 * 将文件以NSDictionry格式写入指定的文件.
 * flag:(YES)先将内容输出到一个临时文件,输出完成后,再重命名为目标文件;NO,直接输出到目标文件,可能会损坏文件.
 */
- (BOOL)writeToFile:(NSString *)path
         atomically:(BOOL)flag;

/*!
 * @method writeToFile:atomically:usingConverter:
 * 使用指定的block,将内容输出到文件.如果指定的block为nil或者block返回的结果为nil,则调用默认的从文件初始化的方法
 * flag:(YES)先将内容输出到一个临时文件,输出完成后,再重命名为目标文件;NO,直接输出到目标文件,可能会损坏文件.
 */
- (BOOL)writeToFile:(NSString *)path
         atomically:(BOOL)flag
     usingConverter:(ConverterToFile)ctf;

/*!
 * @method allColors
 * 以字典形式返回所有字符串,要求以颜色名为键,以RGB为值.
 */
- (NSDictionary *)allColors;
@end
