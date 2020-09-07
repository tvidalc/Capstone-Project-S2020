//
// Created by liyang on 4/1/20.
//

#ifndef SRC_MATLAB_H
#define SRC_MATLAB_H

#include <vector>

namespace matlab
{
    template <typename T_>
    struct RangeInfo{
        T_ begin;
        T_ inc;
        T_ end;

        RangeInfo()=default;

        RangeInfo( T_ b_, T_ i_, T_ e_ )
                : begin(b_),inc(i_),end(e_)
        {}
    };

    template <typename T_>
    std::vector<T_>
    colonRange(T_ begin, T_ inc, T_ end) {
        int N = static_cast<int>( (end-begin) / inc + 0.5 ) + 1 ;
        std::vector<T_> array;
        array.reserve( N );
        while(begin <= end) {
            array.emplace_back(begin);
            begin += inc;         // could recode to better handle rounding errors
        }
        return array;
    }

    template <typename T_>
    std::vector<T_>
    colonN(T_ begin, T_ inc, int N) {
        std::vector<T_> array( N );
        for ( int i = 0; i < N; ++i ) {
            array[i] = begin;
            begin += inc;         // could recode to better handle rounding errors
        }
        return array;
    }

    template <typename T_>
    std::vector<T_>
    linspace( T_ begin, T_ end, int N) {
        std::vector<T_> array;
        T_ inc = 0;
        if ( end == begin )
            N = 1;

        array.resize( N, begin );
        if ( N == 1 )
        {
            end = begin;

            return array;

        } else {

            inc = (end - begin) / (N - 1);


            while (begin <= end) {
                array.emplace_back(begin);
                begin += inc;           // could recode to better handle rounding errors
            }
            return array;
        }
    }

    template <typename T_>
    void
    mesh_grid( std::vector<T_>& grid, const std::vector<T_>& xg, const std::vector<T_>& yg, const std::vector<T_>& zg )
    {
        const int X = (int)xg.size();
        const int Y = (int)yg.size();
        const int Z = (int)zg.size();

        grid.resize( X * Y * Z * 3 );
        for ( int z = 0; z < Z; ++z )
            for ( int y = 0; y < Y; ++y )
                for ( int x = 0; x < X; ++x )
                {
                    int idx = ( x + y*X + z*X*Y ) * 3;
                    grid[ idx ]   = xg[x];
                    grid[ idx+1 ] = yg[y];
                    grid[ idx+2 ] = zg[z];
                }
    }


    template <typename T_>
    void
    mesh_grid( std::vector<T_>& grid, const RangeInfo<T_>& xg, const RangeInfo<T_>& yg, const RangeInfo<T_>& zg )
    {
        std::vector<T_> x_samples = colonRange<float>( xg.begin, xg.inc, xg.end );
        std::vector<T_> y_samples = colonRange<float>( yg.begin, yg.inc, yg.end );
        std::vector<T_> z_samples = colonRange<float>( zg.begin, zg.inc, zg.end );
        mesh_grid<T_>( grid, x_samples, y_samples, z_samples );
    }

}

#endif //SRC_MATLAB_H
