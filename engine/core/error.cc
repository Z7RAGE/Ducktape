/*
MIT License

Copyright (c) 2021 - 2025 Aryan Baburajan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <core/error.h>

namespace DT
{
    Error::Error(const std::string &_error) : error(_error)
    {
        handled = false;
    }

    Error::~Error()
    {
        if (handled)
            return;

        std::cout << "[FATAL] Unhandled error: " + error.value() << ".\n";
        abort();
    }

    bool Error::HasError()
    {
        return error.has_value();
    }

    std::string &Error::GetError()
    {
        handled = true;
        assert(HasError());
        return error.value();
    }

    void Error::Log(const std::string &errorContext)
    {
        handled = true;
        if (!HasError())
            return;
        std::cout << "" << (errorContext != "" ? errorContext + "\n      " : "") << error.value();
    }

    void Error::Err(const std::string &errorContext)
    {
        handled = true;
        if (!HasError())
            return;
        std::cout << "" << (errorContext != "" ? errorContext + "\n      " : "") << error.value();
    }

    void Error::Fatal(const std::string &errorContext)
    {
        handled = true;
        if (!HasError())
            return;
        std::cout << "[FATAL] " << (errorContext != "" ? errorContext + "\n        " : "") << error.value();
        abort();
    }
}