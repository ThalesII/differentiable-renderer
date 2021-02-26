#pragma once

#include <ImfRgba.h>
#include <ImfRgbaFile.h>
#include "vector.hpp"

namespace drt {

static void write_exr(const char *fname, const Vec3 *data,
    std::size_t width, std::size_t height)
{
    std::vector<Imf::Rgba> pixels;
    pixels.reserve(width * height);
    for (std::size_t i = 0; i < height; ++i) {
        for (std::size_t j = 0; j < width; ++j) {
            Vec3 rgb = data[i*width + j];
            pixels.emplace_back(rgb[0], rgb[1], rgb[2], 1.);
        }
    }
    Imf::RgbaOutputFile file(fname, width, height, Imf::WRITE_RGBA);
    file.setFrameBuffer(pixels.data(), 1, width);
    file.writePixels(height);
}

/*
void write_json(const char *fname, cube& img)
{
    FILE *fp = fopen(fname, "w");
    fprintf(fp, "[\n");
    for (int i = 0; i < img.n_rows; ++i) {
        fprintf(fp, "  [\n");
        for (int j = 0; j < img.n_cols; ++j) {
            fprintf(fp, "    [");
            for (int k = 0; k < img.n_slices; ++k) {
                fprintf(fp, "%f", img(i, j, k));
                if (k != img.n_slices - 1) {
                    fprintf(fp, ", ");
                }
            }
            fprintf(fp, "]");
            if (j != img.n_cols - 1) {
                fprintf(fp, ", ");
            }
            fprintf(fp, "\n");
        }
        fprintf(fp, "  ]");
        if (i != img.n_rows - 1) {
            fprintf(fp, ", ");
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "]\n");
    fclose(fp);
}
*/

}
