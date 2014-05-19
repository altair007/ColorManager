//
//  ColorDictionary.h
//  ColorManager
//
//  Created by   颜风 on 14-5-15.
//  Copyright (c) 2014年 Shadow. All rights reserved.
//

#import <Foundation/Foundation.h>
@class Rgb; // 用于表示颜色的RGB值.

@protocol ColorDictionary <NSObject>
@required
/*!
 * @method colorNameForRgb:
 * 返回RGB值对应的颜色名.
 */
- (NSString *)colorNameForRgb:(Rgb *)aRgb;

/*!
 * @method rgbForColorName:
 * 返回颜色名对应的RGB值.
 */
- (Rgb *)rgbForColorName:(NSString *)aColorName;

/*!
 * @method setColorName:forRgb:
 * 为某个rgb值,设置颜色名称.如果颜色名称已经存在,则会修改此颜色名称.如果rgb值不存在,则添加.如果颜色值为nil则会删除此rgb关联的颜色.
 * 允许将颜色名设为[NSNull null];
 */
- (void)setColorName:(NSString *)aColorname
              forRgb:(Rgb *)aRgb;

/*!
 * @method setRgb:forColorName:
 * 为某个颜色名称,设置rgb值.如果此颜色的rgb值已经存在,则会修改此颜色名称.如果颜色名称不存在,则添加.如果新rgb智为nil则会删除此颜色名关联的颜色.
 * 允许将rgb值设为[NSNull null];
 */
- (void)setRgb:(Rgb *)aRgb
  forColorName:(NSString *)aColorName;

/*!
 * @method allColors
 * 以字典形式返回存储的颜色信息.要求以颜色名为键,以RGB为值.
 */
- (NSDictionary *)allColors;
@end
/*!
 * @class ColorDictionary
 * 可用于颜色管理的委托.你可以为颜色管理类定义自己的委托类,只要它同时符合ColorDicionary和NSCopying协议.
 */
@interface ColorDictionary : NSObject <ColorDictionary>
#pragma mark - 属性
@property (nonatomic, strong)NSMutableDictionary * dict; // 存储颜色相关数据.以颜色名为键,以RGB为止.
#pragma mark - 便利构造函数
/*!
 * @method colorDictionary
 * 创建一个空的colorDictionary对象.
 */
+(instancetype)colorDictionary;
@end