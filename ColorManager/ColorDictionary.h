//
//  ColorDictionary.h
//  ColorManager
//
//  Created by   颜风 on 14-5-15.
//  Copyright (c) 2014年 Shadow. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Rgb; // 用于表示颜色的RGB值.

/**
 *  协议,用来限定用来作为颜色管理类的委托的对象需要符号的要求
 */
@protocol ColorDictionary <NSObject>
#pragma mark - 必选方法.
@required
/**
 *  返回Rgb对象对应的颜色名.
 *
 *  @param aRgb 要查询其对应颜色名的Rgb对象.
 *
 *  @return Rgb对象对应的颜色名.
 */
- (NSString *)colorNameForRgb:(Rgb *)aRgb;

/**
 *  返回颜色名对应的Rgb对象.
 *
 *  @param aColorName 要查询其对应的Rgb对象的颜色名.
 *
 *  @return 指定颜色名对应的Rgb对象.
 */
- (Rgb *)rgbForColorName:(NSString *)aColorName;

/**
 *  设置,更改aRgb对应的颜色名;如果aColorName为nil,则删除aRgb对象相关的颜色数据;如果不存在aRgb,则添加.
 *
 *  @param aColorname 新的颜色名
 *  @param aRgb       一个Rgb对象.
 */
- (void)setColorName:(NSString *)aColorname
              forRgb:(Rgb *)aRgb;

/**
 *  设置,更改aColorName对应的Rgb对象;如果aColorName为nil,则删除aColorName相关的颜色数据;如果不存在aColorName,则添加.
 *
 *  @param aRgb       新的颜色名.
 *  @param aColorName 一个Rgb对象.
 */
- (void)setRgb:(Rgb *)aRgb
  forColorName:(NSString *)aColorName;

/**
 *  以字典形式返回存储的颜色数据.
 *
 *  @return 一个含有所有颜色数据的字典,其中以颜色名为键,以Rgb对象为值.
 */
- (NSDictionary *)allColors;
@end

/**
 *  一个符合ColorDictionay协议的Demo.
 */
@interface ColorDictionary : NSObject <ColorDictionary>
#pragma mark - 属性
@property (nonatomic, strong)NSMutableDictionary * dict; //!< 存储颜色相关数据.以颜色名为键,以RGB为值.
#pragma mark - 便利构造函数
/**
 *  便利构造器,创建一个空的ColorDictionary对象.
 *
 *  @return 一个空的ColorDictionary对象.
 */
+(instancetype)colorDictionary;
@end