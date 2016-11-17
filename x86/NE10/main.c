//
//  main.c
//  NE10
//
//  Created by Ruben Perez on 11/9/16.
//  Copyright © 2016 Ruben Perez. All rights reserved.
//

#include <stdio.h>

#include "NE10.h"

int main(int argc, const char * argv[]) {
    
	ne10_fft_cfg_float32_t configuration = 0;
	ne10_int32_t fftSize = 15;
	
	ne10_init();
	configuration = ne10_fft_alloc_c2c_float32(fftSize);
    
	printf("%d\n", __x86_64__);
    
	return 0;

}
