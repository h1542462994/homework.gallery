class Vector {
    /**
     * 
     * @param {number} x 
     * @param {number} y 
     */
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }

    /**
     * @type number
     */
    x;
    /**
     * @type number
     */
    y;
}

class ColorArgb {
    /**
     * 
     * @param {number} r 
     * @param {number} g 
     * @param {number} b 
     * @param {number} a 
     */
    constructor(
        r,g,b,a
    ){
        this.r = r;
        this.g = g;
        this.b = b;
        this.a = a;
    }

    /**
     * @type number
     */
    r;
    /**
     * @type number
     */
    g;
    /**
     * @type number
     */
    b;
    /**
     * @type number
     */
    a;

    getColorStr() {
        return `rgba(${this.r},${this.g},${this.b},${this.a})`
    }

    static random() {
        let r = Math.random() * 128 + 127;
        let g = Math.random() * 128 + 127;
        let b = Math.random() * 128 + 127;
        let a = 1.0;
        return new ColorArgb(
            r,g,b,a
        )
    }
}

class StarProperty {
    /**
     * 
     * @param {Vector} position 
     * @param {number} angle 
     * @param {number} radius 
     * @param {ColorArgb} color 
     */
    constructor(
        position,
        angle,
        radius,
        color
    ) {
        this.position = position;
        this.angle = angle;
        this.radius = radius;
        this.color = color;
    }

    /**
     * 星形的位置
     * @type Vector
     */
    position;
    /**
     * 星形的角度
     * @type number
     */
    angle;
    /**
     * 星形的直径
     * @type number
     */
    radius;
    /**
     * @type ColorArgb
     */
    color;
}

class StarAnimationProperty {
    /**
     * 
     * @param {Vector} position 
     * @param {number} angle 
     * @param {number} radius 
     * @param {ColorArgb} baseColor 
     * @param {number} duration 
     */
    constructor(
        position,
        angle,
        radius,
        baseColor,
        duration
    ) {
        this.position = position;
        this.angle = angle;
        this.radius = radius;
        this.baseColor = baseColor;
        this.duration = duration;
        this.tick = 0;
    }

    /**
     * @type Vector
     */
    position;
    /**
     * @type number
     */
    angle;
    /**
     * @type number
     */
    radius;
    /**
     * @type ColorArgb
     */
    baseColor;
    /**
     * @type number
     */
    duration;
    /**
     * @type number
     */
    tick;

    getStarProperty() {
        let alpha = 0;
        if (this.tick <= this.duration / 2) {
            alpha = this.tick * 2 / this.duration;
        } else {
            alpha = 1 - (this.tick - this.duration / 2) * 2 / this.duration;
        }
        let paintColor = new ColorArgb(
            this.baseColor.r,
            this.baseColor.g,
            this.baseColor.b,
            alpha
        )

        return new StarProperty(
            this.position,
            this.angle,
            this.radius,
            paintColor,
        )
    }
}

class StarPainter {
    constructor(canvas) {
        this.canvas = canvas;
        this.canvasContext = canvas.getContext('2d');
        this.collection = [];
    }

    /**
     * @type Element
     */
    canvas;
    /**
     * @type CanvasRenderingContext2D
     */
    canvasContext;
    /**
     * @type Array<StarProperty>
     */
    collection;

    add(property) {
        this.collection.push(property)
        this.doFrame();
    }

    clear() {
        this.canvasContext.clearRect(0, 0, window.innerWidth, window.innerHeight);
    }

    doFrame() {
        this.clear();
        this.collection.forEach(element => {
            this.draw(element);
        });
    }

    /**
     * @param {StarProperty} property 
     */
    draw(property) {
        // 2/5 * pi
        let duration = 4.0 / 5.0 * Math.PI;
        let angle1 = property.angle;
        let context = this.canvasContext;
        context.fillStyle = property.color.getColorStr();
        context.beginPath();
        for(let i = 0; i <= 5; i++) {
            let point = this.getPoint(property, angle1);
            if (i == 0) {
                context.moveTo(point.x, point.y);
            } else if(i < 5)  {
                context.lineTo(point.x, point.y);
            } else {
                let endPoint = this.getPoint(property, property.angle);
                context.lineTo(endPoint.x, endPoint.y);
            }
            angle1 += duration;
        }
        context.stroke();
        context.fill();
    }

    /**
     * 
     * @param {StarProperty} property 
     * @param {number} angle
     */
    getPoint(property, angle) {
        let x = property.position.x + property.radius * Math.sin(angle);
        let y = property.position.y + property.radius * Math.cos(angle);
        return new Vector(x, y);
    }
}

class StarControl {
    constructor() {
        this.stoped = true;
        this.global_tick = 0;
        this.collection = [];
    }

    /**
     * 开始动画
     */
    startAnime() {
        if (this.stoped)  {
            this.stoped = false;
            this.handler = window.setInterval(this.timer_each, 50);
        }
        
    }

    /**
     * 停止动画
     */
    stopAnime() {
        if (!this.stoped) {
            this.stoped = true;
            window.clearInterval(this.handler);
        }  
    }

    /**
     * 动画是否停止
     * @type boolean
     */
    stoped;

    /**
     * TimeHander
     * @type number
     */
    handler;

    /**
     * 全局计时
     * @type number
     */
    global_tick;

    /**
     * 集合
     * @type Array<StarAnimationProperty>
     */
    collection;

    /**
     * 100ms触发1次。
     */
    timer_each() {
        // no using <this>, starControl instead.
        //console.log(starControl.global_tick);
        let generateSpan = 4;
        let renderSpan = 1;
        
        if (starControl.global_tick % generateSpan === 0) {
            starControl.generate();
        }

        if (starControl.global_tick % renderSpan === 0) {
            starControl.doFrame();
        }

        starControl.global_tick += 1;
    }

    doFrame() {
        console.log('onFrame')
        this.collection.forEach((value) => {
            value.tick += 1;
        })
        this.collection = this.collection.filter((value, index) => {
            return value.tick < value.duration;
        })
        starPainter.collection = this.collection.map((value) => {
            return value.getStarProperty();
        })
        starPainter.doFrame();
        console.log(starPainter.collection)
    }

    /**
     * 创建一个动画对象
     */
    generate() {
        
        /**
         * 生成一个30到60的随机数
         */
        let radius = Math.random() * 30 + 30;
        let angle = Math.random() * 2 * Math.PI;
        console.log('onGenerate');
        let positionX = Math.random() * window.innerWidth;
        let positionY = Math.random() * window.innerHeight;
        
        let color = ColorArgb.random();

        let starAnimationProperty = new StarAnimationProperty(
            new Vector(positionX, positionY),
            angle,
            radius,
            color,
            100
        )
        this.collection.push(starAnimationProperty);
        console.log(starControl.collection)
        
    }

}

/**
 * @type StarPainter
 */
var starPainter;
/**
 * @type StarControl
 */
var starControl;
/**
 * @type Element
 */
var buttonStart;

/**
 * 初始化代码
 */
function init() {
    let canvas = document.querySelector('#canvasStar');
    starPainter = new StarPainter(canvas);
    starControl = new StarControl();
    onWindowResize();
    window.addEventListener('resize', onWindowResize);
    buttonStart = document.querySelector('#buttonStart');
    buttonStart.addEventListener('click', onStopChanged)

    // starPainter.add(
    //     new StarProperty(
    //         new Vector(600, 400),
    //         0,
    //         40,
    //         'cyan'
    //     )
    // )

}

/**
 * 实时调整大小为全屏。
 */
function onWindowResize() {
    starPainter.canvas.setAttribute('width', `${window.innerWidth}px`);
    starPainter.canvas.setAttribute('height', `${window.innerHeight}px`);
    starPainter.doFrame();
}

/**
 * 点击了开始动画或者
 */
function onStopChanged() {
    if (starControl.stoped) {
        starControl.startAnime();
        buttonStart.setAttribute('value', '结束');
    } else {
        starControl.stopAnime();
        buttonStart.setAttribute('value', '开始');
    }
}

init();