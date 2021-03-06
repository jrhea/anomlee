// main.cpp
#include <fdeep/fdeep.hpp>
#include <CImg.h>

fdeep::tensor5 cimg_to_tensor5(const cimg_library::CImg<unsigned char>& image,
    fdeep::float_type low = 0.0f, fdeep::float_type high = 1.0f)
{
    const int width = image.width();
    const int height = image.height();
    const int channels = image.spectrum();
    std::cout << "(width,height,channels) = (" << width << "," << height << "," << channels << ")" << std::endl;
    std::vector<unsigned char> pixels;
    pixels.reserve(height * width * channels);

    // CImg stores the pixels of an image non-interleaved:
    // http://cimg.eu/reference/group__cimg__storage.html
    // This loop changes the order to interleaved,
    // e.e. RRRGGGBBB to RGBRGBRGB for 3-channel images.
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            for (int c = 0; c < channels; c++)
            {
                pixels.push_back(image(x, y, 0, c));
            }
        }
    }

    return fdeep::tensor5_from_bytes(pixels.data(), 1, 1, 784,
        low, high);
}

int main()
{
    const cimg_library::CImg<unsigned char> image("./build/test5.png");
    const auto model = fdeep::load_model("./build/digit-model.json");
    // Use the correct scaling, i.e., low and high.
    const auto input = cimg_to_tensor5(image, 0.0f, 1.0f);
    auto start = std::chrono::high_resolution_clock::now();
    const auto result = model.predict_class({input});
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    std::cout << "Predicted number: " << result << " in " << microseconds << " microseconds." << std::endl;
}