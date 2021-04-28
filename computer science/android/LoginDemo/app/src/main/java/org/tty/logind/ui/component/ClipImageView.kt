package org.tty.logind.ui.component

import android.annotation.SuppressLint
import android.content.Context
import android.graphics.*
import android.graphics.drawable.BitmapDrawable
import android.util.AttributeSet
import androidx.appcompat.widget.AppCompatImageView

class ClipImageView(context: Context, attrs: AttributeSet?, defStyleAttr: Int): AppCompatImageView(context, attrs , defStyleAttr) {
    constructor(context: Context): this(context, null)
    constructor(context: Context, attrs: AttributeSet?): this(context, attrs, 0)
    private lateinit var mPaint: Paint
    private var mRadius: Float = 0.0f
    private var mScale: Float = 0.0f

    override fun onMeasure(widthMeasureSpec: Int, heightMeasureSpec: Int) {
        super.onMeasure(widthMeasureSpec, heightMeasureSpec)
        val size = minOf(measuredWidth, measuredHeight)
        mRadius = (size / 2).toFloat()
        setMeasuredDimension(size, size)
    }

    @SuppressLint("DrawAllocation")
    override fun onDraw(canvas: Canvas?) {
        mPaint = Paint()
        if (drawable != null) {
            val bitmap = (drawable as BitmapDrawable).bitmap
            val bitmapShader = BitmapShader(bitmap, Shader.TileMode.CLAMP, Shader.TileMode.CLAMP)
            mScale = (mRadius * 2.0f) / minOf(bitmap.width, bitmap.height)
            val matrix = Matrix()
            matrix.setScale(mScale, mScale)
            bitmapShader.setLocalMatrix(matrix)
            mPaint.shader = bitmapShader
            canvas?.drawCircle(mRadius, mRadius, mRadius, mPaint)
        } else {
            super.onDraw(canvas)
        }
    }
}