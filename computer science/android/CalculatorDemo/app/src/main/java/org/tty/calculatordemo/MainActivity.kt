package org.tty.calculatordemo

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import androidx.appcompat.widget.AppCompatButton
import androidx.appcompat.widget.AppCompatTextView
import net.objecthunter.exp4j.Expression
import net.objecthunter.exp4j.ExpressionBuilder
import java.lang.Error
import java.lang.Exception
import java.math.BigDecimal
import kotlin.math.exp

class MainActivity : AppCompatActivity(), CalcEventListener {
    class MainActivityViewHolder(mainActivity: MainActivity) {
        var calcEventListener: CalcEventListener? = null

        private val buttonAC: AppCompatButton = mainActivity.findViewById(R.id.button_ac)
        private val buttonDEL: AppCompatButton = mainActivity.findViewById(R.id.button_delete)
        private val buttonLeft: AppCompatButton = mainActivity.findViewById(R.id.button_left)
        private val buttonRight: AppCompatButton = mainActivity.findViewById(R.id.button_right)
        private val button0: AppCompatButton = mainActivity.findViewById(R.id.button_n_0)
        private val button1: AppCompatButton = mainActivity.findViewById(R.id.button_n_1)
        private val button2: AppCompatButton = mainActivity.findViewById(R.id.button_n_2)
        private val button3: AppCompatButton = mainActivity.findViewById(R.id.button_n_3)
        private val button4: AppCompatButton = mainActivity.findViewById(R.id.button_n_4)
        private val button5: AppCompatButton = mainActivity.findViewById(R.id.button_n_5)
        private val button6: AppCompatButton = mainActivity.findViewById(R.id.button_n_6)
        private val button7: AppCompatButton = mainActivity.findViewById(R.id.button_n_7)
        private val button8: AppCompatButton = mainActivity.findViewById(R.id.button_n_8)
        private val button9: AppCompatButton = mainActivity.findViewById(R.id.button_n_9)
        private val buttonDot: AppCompatButton = mainActivity.findViewById(R.id.button_dot)
        private val buttonDivide: AppCompatButton = mainActivity.findViewById(R.id.button_divide)
        private val buttonMultiply: AppCompatButton = mainActivity.findViewById(R.id.button_multiply)
        private val buttonAdd: AppCompatButton = mainActivity.findViewById(R.id.button_add)
        private val buttonSubtract: AppCompatButton = mainActivity.findViewById(R.id.button_subtract)
        private val buttonEquals: AppCompatButton = mainActivity.findViewById(R.id.button_equal)
        val textViewInput: AppCompatTextView = mainActivity.findViewById(R.id.textView_inputRegion)
        val textViewResult: AppCompatTextView = mainActivity.findViewById(R.id.textView_inputResult)

        fun registerEvent() {
            buttonAC.setOnClickListener { calcEventListener?.onCalcAction(CalcAction.AC) }
            buttonDEL.setOnClickListener { calcEventListener?.onCalcAction(CalcAction.DEL) }
            buttonEquals.setOnClickListener { calcEventListener?.onCalcAction(CalcAction.EQUAL) }
            buttonLeft.setOnClickListener { calcEventListener?.onCalcOperator(CalcOperator.LEFT) }
            buttonRight.setOnClickListener { calcEventListener?.onCalcOperator(CalcOperator.RIGHT) }
            buttonDivide.setOnClickListener { calcEventListener?.onCalcOperator(CalcOperator.DIVIDE) }
            buttonMultiply.setOnClickListener { calcEventListener?.onCalcOperator(CalcOperator.MULTIPLY) }
            buttonAdd.setOnClickListener { calcEventListener?.onCalcOperator(CalcOperator.ADD) }
            buttonSubtract.setOnClickListener { calcEventListener?.onCalcOperator(CalcOperator.SUBTRACT) }
            buttonDot.setOnClickListener { calcEventListener?.onDot() }
            button0.setOnClickListener { calcEventListener?.onNumber(0) }
            button1.setOnClickListener { calcEventListener?.onNumber(1) }
            button2.setOnClickListener { calcEventListener?.onNumber(2) }
            button3.setOnClickListener { calcEventListener?.onNumber(3) }
            button4.setOnClickListener { calcEventListener?.onNumber(4) }
            button5.setOnClickListener { calcEventListener?.onNumber(5) }
            button6.setOnClickListener { calcEventListener?.onNumber(6) }
            button7.setOnClickListener { calcEventListener?.onNumber(7) }
            button8.setOnClickListener { calcEventListener?.onNumber(8) }
            button9.setOnClickListener { calcEventListener?.onNumber(9) }
        }
    }

    lateinit var mainActivityViewHolder: MainActivityViewHolder

    var inputStringBuilder = StringBuilder("0")
    var lastRecordResult = "0"
    var hasError = false

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        mainActivityViewHolder = MainActivityViewHolder(this)
        mainActivityViewHolder.calcEventListener = this
        mainActivityViewHolder.registerEvent()
    }

    fun onUpdateUI() {
        val inputValue = inputValue()
        mainActivityViewHolder.textViewInput.text = inputValue
        try {
            // 修改表达式以适应公共格式
            val realExpression = inputValue.replace('×','*').replace('÷','/')
            val expression = ExpressionBuilder(realExpression).build()
            val result = expression.evaluate()
            lastRecordResult = "=" + toRealString(result)
            hasError = false
        } catch (ex: Exception) {
            ex.printStackTrace()
            hasError = true
        }
        mainActivityViewHolder.textViewResult.text = lastRecordResult
    }

    fun toRealString(value: Double): String {
        return value.toString().removeSuffix(".0")
    }

    private fun inputValue(): String {
        return inputStringBuilder.toString()
    }

    private fun lastNumValue(): String {
        val dotDigits = listOf('0','1','2','3','4','5','6','7','8','9','.')
        val lastValueString = StringBuilder()
        val inputValue = inputValue()
        var lastIndex = inputValue.length - 1
        while (lastIndex >= 0 && inputValue[lastIndex] in dotDigits) {
            lastValueString.append(inputValue[lastIndex])
            lastIndex--
        }

        return lastValueString.reverse().toString()
    }

    override fun onCalcAction(calcAction: CalcAction) {
        when (calcAction) {
            CalcAction.AC -> {
                inputStringBuilder.clear()
                inputStringBuilder.append("0")
                lastRecordResult = "0"
                hasError = false
            }
            CalcAction.DEL -> {
                if (inputValue() == "0") {
                    return
                }
                val length = inputStringBuilder.length
                inputStringBuilder.deleteCharAt(length - 1)
                if (inputStringBuilder.isEmpty()) {
                    inputStringBuilder.append("0")
                }
            }
            else -> {
                // ignore
            }
        }
        onUpdateUI()
    }

    override fun onCalcOperator(calcOperator: CalcOperator) {
        when (calcOperator) {
            CalcOperator.LEFT -> {
                inputStringBuilder.append("(")
            }
            CalcOperator.RIGHT -> {
                inputStringBuilder.append(")")
            }
            else -> {
                val normalOperators = listOf('×','÷','+','-')
                if (inputStringBuilder.last() in normalOperators) {
                    inputStringBuilder.deleteCharAt(inputStringBuilder.length - 1)
                }
                inputStringBuilder.append(calcOperator.value)
            }
        }
        onUpdateUI()
    }

    override fun onNumber(number: Int) {
        if (inputValue().last() == '0' && number == 0) {
            return
        } else {
            if (inputValue() == "0") {
                inputStringBuilder.clear()
            }
            inputStringBuilder.append(number.toString())
        }
        onUpdateUI()
    }

    override fun onDot() {
        if (lastNumValue().contains('.')) {
            return
        }
        inputStringBuilder.append('.')
        onUpdateUI()
    }


}

