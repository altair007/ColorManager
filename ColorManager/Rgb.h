//
//  Rgb.h
//  ColorManager
//
//  Created by   颜风 on 14-5-15.
//  Copyright (c) 2014年 Shadow. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 * @class Rgb 
 * 用于颜色的RGB值.
 */
@interface Rgb : NSObject

#pragma mark - 属性

@property (nonatomic, assign)NSUInteger red; // 红 0~255
@property (nonatomic, assign)NSUInteger green; // 绿 0~255
@property (nonatomic, assign)NSUInteger blue; // 蓝 0~255

#pragma mark - 便利构造器
/*!
 * @method rgbWithRed:green:blue;
 * 使用表示红绿蓝的三个整数值便利初始化
 */
+ (instancetype) rgbWithRed:(NSUInteger)red
                      green:(NSUInteger)green
                       blue:(NSUInteger)blue;

/*!
 * @method rgbWithString:
 * 从一个含有Rgb值的字符串读取数据,只分析字符串前六位,每两位表示一个rgb值,依次对应red,green,blue
 */
+ (instancetype)rgbWithString:(NSString *)aString;

#pragma mark - 工具方法
/*!
 * @method numberHexString:step:
 * 把表示十六进制数字的字符串转换成NSNumber对象,以数组形式返回.
 * step:每多少个字符作为一个整体处理.各个部分的字符串块,可选地可以以0x或0X开头.step设为0,则将字符串按照一个整体转换成一个NSnumber;
 * 当step不为0时,字符串长度如果是step的整数倍,则最后一部分子串会被单独处理转换为对应的NSNumber.遇到非法字符,此子串后面的内容会被忽略
 * 但不会影响其他子串!此方法以numberHexString:为基础.
 *
 */
+ (NSArray *) numberHexString:(NSString * )aHexString
                         step:(NSUInteger)step;

/*!
 * @method numberHexString:
 * 把表示十六进制的字符串转换成NSNumber对象,可选以0x或0X为前缀,前缀非必须.遇到非法字符,后面的内容会被忽略.
 */
+ (NSNumber *) numberHexString:(NSString *)aHexString;

#pragma mark - 初始化方法

/*!
 * @method initWithRed:green:blue;
 * 使用表示红绿蓝的三个整数值便利初始化
 */
- (instancetype) initWithRed:(NSUInteger)red
                       green:(NSUInteger)green
                        blue:(NSUInteger)blue;

/*!
 * @method initWithString:
 * 从一个含有Rgb值的字符串读取数据,只分析字符串前六位,每两位表示一个rgb值,依次对应red,green,blue
 */
- (instancetype) initWithString:(NSString *)aString;

#pragma mark - 实例方法

/*!
 * @method isEqualToRgb:
 * 判断两个Rgb对象是否等价
 */
- (BOOL) isEqualToRgb:(Rgb *)otherRgb;

/*!
 * @method stringRgb:
 * 将Rgb转换成三个十六进制数表示的字符串.每个rgb值用两位十六进制数表示,数值太小不需要两位十六进制数的,直接首位补零!
 * flag为YES,转换为FFFFFF形式;flag为NO,转换为ffff形式.
 */
- (NSString *)stringRgb:(BOOL)flag;

/*!
 * @mthod setRed:
 * 设置red属性.数值输入必须在0~255之间.输入小于0,取0;大于255,取255.
 */
- (void)setRed:(NSUInteger)red;

/*!
 * @mthod setGreen:
 * 设置green属性.数值输入必须在0~255之间.输入小于0或大于255,取255.
 */
- (void)setGreen:(NSUInteger)green;

/*!
 * @mthod setBlue:
 * 设置blue属性.数值输入必须在0~255之间.输入小于0或大于255,取255.
 */
- (void)setBlue:(NSUInteger)blue;

@end
