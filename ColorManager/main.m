//
//  main.m
//  ColorManager
//
//  Created by   颜风 on 14-5-15.
//  Copyright (c) 2014年 Shadow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ColorManager.h"
#import "Rgb.h"

int main(int argc, const char * argv[])
{
    @autoreleasepool
    {
        // 测试 Demo:请确保文件路径正确!
        ColorManager * colorManager = [ColorManager colorManagerWithDelegate:[ColorDictionary colorDictionary] contentOfFile:@"color.plist"];
        [colorManager writeToFile:@"/tmp/out.plist" atomically:YES usingConverter:^BOOL(NSDictionary *dict, NSString *path, BOOL flag) {
            return NO;
        }];
    }
    return 0;
}

