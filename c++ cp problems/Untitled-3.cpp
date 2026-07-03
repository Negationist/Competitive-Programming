                if(!i && !j) continue; //figure out zero stuff later
                if(k==0){ //we are going right
                    if(j-1<0){
                        dp[i][j][k][0] = dp[i][j][k][1] = -inf;
                    } else{
                        dp[i][j][k][0] = max(dp[i][j-1][0][0],dp[i][j-1][1][0])+a[i][j];
                        dp[i][j][k][1] = max({dp[i][j-1][0][1]+a[i][j],dp[i][j-1][1][1]+a[i][j],dp[i][j-1][2][1]});
                    }
                } else if(k==1){ //we are going down
                    if(i-1<0){
                        dp[i][j][k][0] = dp[i][j][k][1] = -inf;
                    } else{
                        dp[i][j][k][0] = max(dp[i-1][j][0][0],dp[i-1][j][1][0])+a[i][j];
                        dp[i][j][k][1] = max({dp[i-1][j][0][1]+a[i][j],dp[i-1][j][1][1]+a[i][j],dp[i-1][j][2][1]+a[i][j]});
                    }
                } else{ //we are going left
                    if(j+1==m){
                        dp[i][j][k][0] = dp[i][j][k][1] = -inf;
                    } else{
                        dp[i][j][k][0] = -inf;
                        dp[i][j][k][1] = max({dp[i][j+1][0][0],dp[i][j+1][1][0]+a[i][j]});
                    }
                }