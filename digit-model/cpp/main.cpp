// main.cpp
#include <fdeep/fdeep.hpp>
#include <CImg.h>

fdeep::tensor5 cimg_to_tensor5(const cimg_library::CImg<unsigned char>& image,
    fdeep::float_type low = 0.0f, fdeep::float_type high = 1.0f)
{
    const int width = image.width();
    const int height = image.height();
    const int channels = image.spectrum();

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

    return fdeep::tensor5_from_bytes(pixels.data(), height, width, channels,
        low, high);
}

int main()
{
    /*const auto model = fdeep::load_model("./build/digit-model.json");
    
    const auto result = model.predict(
        {fdeep::tensor5(fdeep::shape5(1, 1, 1, 1, 784), {})});
    std::cout << fdeep::show_tensor5s(result) << std::endl;*/


    const cimg_library::CImg<unsigned char> image("./build/test3.png");
    const auto model = fdeep::load_model("./build/digit-model.json");
    // Use the correct scaling, i.e., low and high.
    const auto input = cimg_to_tensor5(image, 0.0f, 1.0f);
    const auto result = model.predict_class({input});
    std::cout << result << std::endl;
}