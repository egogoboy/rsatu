#ifndef NUM_H
#define NUM_H

#include <algorithm>
#include <string>
#include <iostream>

class Num {
    
    public:
        
        Num(int value) {
            _value = value;
            _makeBinView();
            _doRightCode();
            _doReverseCode();
            _doAdditionalCode();
            _doModCode();
        }

        std::string getBinCode() {
            return _binView;
        }

        std::string getRightCode() {
            return _rightCode;
        }

        std::string getReverseCode() {
            return _reverseCode;
        }

        std::string getAdditionalCode() {
            return _additionalCode;
        }

        std::string getModCode() {
            return _modCode;
        }

    private:

        void _doRightCode() {
            _rightCode = (_value < 0 ? "1." : "0.") + _binView;
        }

        void _doReverseCode() {
            _reverseCode = _rightCode;
            if (_value < 0) {
                for (int i = 2; i < _reverseCode.size(); i++)
                    _reverseCode[i] = (_reverseCode[i] == '0' ? '1' : '0');
            }
       }

        void _doAdditionalCode() {
            _additionalCode = _reverseCode;

            if (_value < 0) {
 
                bool carry = true;
                for (int i = _additionalCode.size() - 1; i >= 0; i--) {
                    if (_additionalCode[i] != '.') {
                        if (carry) {
                            if (_additionalCode[i] == '1') {
                                _additionalCode[i] = '0';
                            }
                            else {
                                _additionalCode[i] = '1';
                                carry = false;
                            }
                        }
                    }
                }

            }
       }

        void _doModCode() {
            _modCode = (_value < 0 ? "1" : "0") + _additionalCode;
        }

        void _makeBinView() {
            int x = std::abs(_value);

            while (x != 0) {
                _binView += std::to_string(x % 2);
                x /= 2;
            }

            std::reverse(_binView.begin(), _binView.end());
       }

        int _value;
        std::string _binView;
        std::string _rightCode;
        std::string _reverseCode;
        std::string _additionalCode;
        std::string _modCode;

};

#endif //NUM_H
