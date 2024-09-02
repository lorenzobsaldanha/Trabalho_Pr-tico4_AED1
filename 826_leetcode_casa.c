
void merge_sort_crescente( int *array, int tamanho ){
    int *left, *right;
    int meio, i,j = 0;
    int tamanhoLeft, tamanhoRight;
    if( tamanho <= 1 ){
        return ;
    }
    left = ( int* ) malloc ( sizeof( int ) * tamanho );
    right = ( int* ) malloc ( sizeof( int ) * tamanho );

    meio = tamanho / 2;
    tamanhoLeft = meio;
    tamanhoRight = tamanho - meio;
    for( i = 0; i < meio; i++ ){
        left[ i ] = array[ i ];
    }
    for( i = meio; i < tamanho; i++ ){
        right[ j ] = array[ i ];
        j ++;
    }

 merge_sort_crescente( left, tamanhoLeft );
   merge_sort_crescente( right, tamanhoRight );
    merge_crescente( left, right, array, tamanho );
}

void merge_crescente( int *left, int *right, int *array, int tamanho ){
           int tamanhoLeft = tamanho / 2;
           int tamanhoRight = tamanho - tamanhoLeft;
           int i = 0, l = 0, r = 0;

           while(l < tamanhoLeft && r < tamanhoRight ){
            if( left[ l ] > right[ r ] ){
                array[ i ] = right[ r ];
                i ++;
                r ++;
            }
            else{
                array[ i ] = left[ l ];
                i ++;
                l ++;
            }
           }
           while( l < tamanhoLeft ){
            array[ i ] = left[ l ];
            i ++;
            l ++;
           }
           while( r < tamanhoRight ){
            array[ i ] = right[ r ];
            i ++;
            r ++;
           }
}


void merge_sort_decrescente( int *arrayProfit, int *arrayDifficulty, int tamanho ){
    int *leftProfit, *rightProfit, *leftDifficulty, *rightDifficulty;
    int meio, i,j = 0;
    int tamanhoLeft, tamanhoRight;
    if( tamanho <= 1 ){
        return ;
    }
    leftProfit = ( int* ) malloc ( sizeof( int ) * tamanho );
    rightProfit = ( int* ) malloc ( sizeof( int ) * tamanho );
     leftDifficulty = ( int* ) malloc ( sizeof( int ) * tamanho );
    rightDifficulty = ( int* ) malloc ( sizeof( int ) * tamanho );

    meio = tamanho / 2;
    tamanhoLeft = meio;
    tamanhoRight = tamanho - meio;
    for( i = 0; i < meio; i++ ){
        leftProfit[ i ] = arrayProfit[ i ];
        leftDifficulty[ i ] = arrayDifficulty[ i ];
    }
    for( i = meio; i < tamanho; i++ ){
        rightProfit[ j ] = arrayProfit[ i ];
        rightDifficulty[ j ] = arrayDifficulty[ i ];
        j ++;
    }
      

 merge_sort_decrescente( leftProfit, leftDifficulty, tamanhoLeft );
   merge_sort_decrescente( rightProfit, rightDifficulty, tamanhoRight );
  
    merge_decrescente( leftProfit, rightProfit, arrayProfit, leftDifficulty, rightDifficulty, arrayDifficulty, tamanho );
}

void merge_decrescente( int *leftProfit, int *rightProfit, int *arrayProfit, int *leftDifficulty, int *rightDifficulty, int *arrayDifficulty, int tamanho ){
           int tamanhoLeft = tamanho / 2;
           int tamanhoRight = tamanho - tamanhoLeft;
           int i = 0, l = 0, r = 0;

           while( l < tamanhoLeft && r < tamanhoRight ){
            if( leftProfit[ l ] > rightProfit[ r ] ){
                arrayProfit[ i ] = leftProfit[ l ];
                arrayDifficulty[ i ] = leftDifficulty[ l ];
                i ++;
                l ++;
            }
            else{
                arrayProfit[ i ] = rightProfit[ r ];
                arrayDifficulty[ i ] = rightDifficulty[ r ];
                i ++;
                r ++;
            }
           }
           while( l < tamanhoLeft ){
            arrayProfit[ i ] = leftProfit[ l ];
            arrayDifficulty[ i ] = leftDifficulty[ l ];
            i ++;
            l ++;
           }
           while( r < tamanhoRight ){
            arrayProfit[ i ] = rightProfit[ r ];
            arrayDifficulty[ i ] = rightDifficulty[ r ];
            i ++;
            r ++;
           }
}



int maxProfitAssignment( int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize ) {
    int i, j, total = 0;
  
    merge_sort_decrescente( profit, difficulty, profitSize );
    for( i = 0; i < difficultySize; i++ ){
    printf( "%d ",difficulty[ i ] );
  }
 
 printf( "\n" );
  for( i = 0; i < profitSize; i++ ){
    printf( "%d ",profit[ i ] );
  }

    merge_sort_crescente( worker, workerSize );
 printf( "\n" );
  for( i = 0; i < workerSize; i++ ){
    printf( "%d ",worker[ i ] );
  }

    for( i = 0; i < difficultySize; i++ ){
        for( j = 0; j < workerSize; j++ ){
            if( worker[ j ] >= difficulty[ i ] ){
                

               total += profit[ i ];
               worker[ j ] = 0;
            }

        }
    }
    return total;
    
}

