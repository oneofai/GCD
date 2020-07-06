//
//  YGViewController.m
//  GCD
//
//  Created by holaux@gmail.com on 07/06/2020.
//  Copyright (c) 2020 holaux@gmail.com. All rights reserved.
//

#import "YGViewController.h"
#import <GCD/GCD.h>

@interface YGViewController ()
@property (weak, nonatomic) IBOutlet UILabel *label;

@property (nonatomic, strong) GCDTimer *timer;

@end

@implementation YGViewController

- (void)viewDidLoad
{
    
    [super viewDidLoad];
    
    _timer = [[GCDTimer alloc] init];
    [_timer countDownEvent:^(float leftTime) {
        self.label.text = [NSString stringWithFormat:@"%.0lfs", leftTime];
    } completionEvent:^{
        self.label.text = @"结束";
    } cancelEvent:^{
        
    } timeIntervalWithSecs:1.0 totalSecs:60];
    [_timer start];
    
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
