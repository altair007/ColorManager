//
//  Rgb.h
//  ColorManager
//
//  Created by   颜风 on 14-5-15.
//  Copyright (c) 2014年 Shadow. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 表示颜色的Rgb数据
@interface Rgb : NSObject

#pragma mark - 属性
@property (nonatomic, assign)NSUInteger red; //!<表示红色,取值范围0~255.
@property (nonatomic, assign)NSUInteger green; //!< 表示绿色,取值范围0~255.
@property (nonatomic, assign)NSUInteger blue; //!< 表示蓝色,取值范围0~255.

#pragma mark - 便利构造器
/**
 * 使用三个表示红,绿,蓝三个颜色Rgb值的整数来创建一个Rgb对象.
 *
 * @warning 当传递给方法0~255范围外的值时,都会默认当做255处理.如果这不是您预期想要的行为,请显式地传递0~255范围内的值.
 *
 * @param red   表示红色,0~255之间的一个整数
 * @param green 表示绿色,0~255之间的一个整数
 * @param blue  表示蓝色,0~255之间的一个整数
 *
 * @return 一个Rgb类对象.
 */
+ (instancetype) rgbWithRed:(NSUInteger)red
                      green:(NSUInteger)green
                       blue:(NSUInteger)blue;

/**
 *  从一个含有Rgb值的字符串读取数据创建Rgb对象.
 *
 *  @param aString 六位字符的字符串,每两位表示一个rgb值,依次对应红,绿,蓝.
 *
 *  @return 一个与aString对应的Rgb对象.失败,返回nil.
 */
+ (instancetype)rgbWithString:(NSString *)aString;

#pragma mark - 工具方法
/**
 *  十六进制字符串转数字数组.
 *
 *  @param aHexString 含有多个十六进制数字的字符串.
 *  @param step       说明每多少个字符作为一个整体处理.各个子串,可选地以0X或者0x开头.step设为0,则将字符串按照一个整体转换成一个NSNumber.
 *
 *  @return 含有NSNumber的数组.
 */
+ (NSArray *) numberHexString:(NSString * )aHexString
                         step:(NSUInteger)step;

/**
 *  十六进制字符串转数字对象.
 *
 *  @param aHexString 含有十六进制数字的字符串.
 *
 *  @return 一个NSNumber对象.
 */
+ (NSNumber *) numberHexString:(NSString *)aHexString;

#pragma mark - 初始化方法

/**
 * 使用三个表示红,绿,蓝三个颜色Rgb值的整数来初始化一个Rgb对象.
 *
 * @warning 当传递给方法0~255范围外的值时,都会默认当做255处理.如果这不是您预期想要的行为,请显式地传递0~255范围内的值.
 *
 * @param red   表示红色,0~255之间的一个整数
 * @param green 表示绿色,0~255之间的一个整数
 * @param blue  表示蓝色,0~255之间的一个整数
 *
 * @return 一个Rgb类对象.
 */
- (instancetype) initWithRed:(NSUInteger)red
                       green:(NSUInteger)green
                        blue:(NSUInteger)blue;

/**
 *  从一个含有Rgb值的字符串读取数据初始化Rgb对象.
 *
 *  @param aString 六位字符的字符串,每两位表示一个rgb值,依次对应红,绿,蓝.
 *
 *  @return 一个与aString对应的Rgb对象.失败,返回nil.
 */
- (instancetype) initWithString:(NSString *)aString;

#pragma mark - 实例方法

/**
 *  判断两个Rgb对象是否等价
 *
 *  @param otherRgb 另一个Rgb对象
 *
 *  @return 如果两个对象为同一对象或者属性相等,则返回YES,否则返回NO.
 */
- (BOOL) isEqualToRgb:(Rgb *)otherRgb;

/**
 *  将Rgb对象转换成含有三个十六进制数的字符串,每个十六进制数占两位.
 *
 *  @param flag YES,则转换为FFFFFF形式;NO,则转换为ffffff形式.
 *
 *  @return 一个十六进制数形式的字符串.
 */
- (NSString *)stringRgb:(BOOL)flag;

/**
 *  设置red属性.
 *
 *  @param red 0~255之间的一个整数.传递小于0或大于255的值,统一取值255.
 */
- (void)setRed:(NSUInteger)red;

/**
 *  设置green属性
 *
 *  @param green 0~255之间的一个整数.传递小于0或大于255的值,统一取值255.
 */
- (void)setGreen:(NSUInteger)green;

/**
 *  设置blue属性.
 *
 *  @param blue 0~255之间的一个整数.传递小于0或大于255的值,统一取值255.
 */
- (void)setBlue:(NSUInteger)blue;
@end
