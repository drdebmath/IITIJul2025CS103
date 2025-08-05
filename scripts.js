let currentSlideIndex = 0;
let slides = [];
const body = document.body;
const fullscreenBtn = document.getElementById('fullscreenBtn');
const darkModeToggle = document.getElementById('darkModeToggle');
const darkModeIcon = darkModeToggle.querySelector('i');

function showSlide(index) {
    if (index >= 0 && index < slides.length) {
        slides.forEach((slide, i) => {
            slide.classList.toggle('active', i === index);
        });
        currentSlideIndex = index;
        updateNavigationButtons();
        updateSlideOutline();
        updateSlideCounter();
    }
}

function nextSlide() {
    if (currentSlideIndex < slides.length - 1) {
        showSlide(currentSlideIndex + 1);
    }
}

function prevSlide() {
    if (currentSlideIndex > 0) {
        showSlide(currentSlideIndex - 1);
    }
}

function updateNavigationButtons() {
    const prevBtn = document.getElementById('prevSlideBtn');
    const nextBtn = document.getElementById('nextSlideBtn');
    if (prevBtn) prevBtn.disabled = currentSlideIndex === 0;
    if (nextBtn) nextBtn.disabled = currentSlideIndex === slides.length - 1;
}

function updateSlideOutline() {
    const outlineItems = document.querySelectorAll('.slide-outline-item');
    // This function's role is now handled by the scroll handler in normal mode,
    // but we keep it for potential use in fullscreen if we ever add the outline back there.
    // For now, it will update based on the fullscreen slide index.
    outlineItems.forEach((item, index) => {
        item.classList.toggle('active', index === currentSlideIndex);
    });
}

function updateSlideCounter() {
    const counter = document.querySelector('.slide-counter');
    if (counter) {
        counter.textContent = `${currentSlideIndex + 1} / ${slides.length}`;
    }
}

document.addEventListener('DOMContentLoaded', () => {
    // Load dark mode preference
    if (localStorage.getItem('darkMode') === 'enabled') {
        body.classList.add('dark-mode');
        darkModeIcon.classList.replace('fa-moon', 'fa-sun');
    }

    // --- Slide Outline Toggle Logic ---
    const slideOutline = document.querySelector('.slide-outline');
    const outlineToggleBtn = document.getElementById('outline-toggle');
    if (outlineToggleBtn && slideOutline) {
        outlineToggleBtn.addEventListener('click', () => {
            slideOutline.classList.toggle('collapsed');
            const icon = outlineToggleBtn.querySelector('i');
            if (slideOutline.classList.contains('collapsed')) {
                icon.classList.remove('fa-chevron-left');
                icon.classList.add('fa-chevron-right');
                outlineToggleBtn.title = "Show Outline";
            } else {
                icon.classList.remove('fa-chevron-right');
                icon.classList.add('fa-chevron-left');
                outlineToggleBtn.title = "Hide Outline";
            }
        });
    }

    // --- Create and append fullscreen navigation buttons ---
    const navDiv = document.createElement('div');
    navDiv.className = 'slide-navigation';
    navDiv.innerHTML = `
        <button id="prevSlideBtn" class="btn btn-secondary slide-nav-btn" title="Previous Slide"><i class="fas fa-chevron-left"></i></button>
        <div class="slide-counter">1 / 10</div>
        <button id="nextSlideBtn" class="btn btn-secondary slide-nav-btn" title="Next Slide"><i class="fas fa-chevron-right"></i></button>
    `;
    body.appendChild(navDiv);

    slides = Array.from(document.querySelectorAll('.slide'));
    document.getElementById('prevSlideBtn').addEventListener('click', prevSlide);
    document.getElementById('nextSlideBtn').addEventListener('click', nextSlide);

    // --- Logic for scroll-based highlighting in normal mode ---
    const outlineItems = document.querySelectorAll('.slide-outline-item');
    const sections = document.querySelectorAll('.slide > h2[id]');

    const handleScroll = () => {
        if (body.classList.contains('fullscreen-mode')) return; // Don't run this logic in fullscreen

        let currentSectionId = '';
        const scrollPosition = window.scrollY;
        
        sections.forEach(section => {
            // Adjust offset to trigger highlight a bit earlier
            const sectionTop = section.offsetTop - 100; 
            if (scrollPosition >= sectionTop) {
                currentSectionId = section.getAttribute('id');
            }
        });

        outlineItems.forEach(item => {
            // Check if item's href matches the current section's ID
            if (item.getAttribute('href') === `#${currentSectionId}`) {
                item.classList.add('active');
            } else {
                item.classList.remove('active');
            }
        });
    };
    
    // Initial call to set the state correctly on page load
    handleScroll(); 
    // Add event listener for scrolling
    window.addEventListener('scroll', handleScroll);

    // Click handler for outline items to also update the active state instantly
    outlineItems.forEach(item => {
        item.addEventListener('click', () => {
            if (body.classList.contains('fullscreen-mode')) return;
            // Remove active class from all items
            outlineItems.forEach(i => i.classList.remove('active'));
            // Add active class to the clicked item
            item.classList.add('active');
        });
    });
});

// Fullscreen Toggle with enhanced animations
fullscreenBtn.addEventListener('click', () => {
    const isFullscreen = body.classList.contains('fullscreen-mode');
    if (!isFullscreen) {
        body.classList.add('fullscreen-mode');
        fullscreenBtn.innerHTML = '<i class="fas fa-compress"></i>';
        fullscreenBtn.title = 'Exit Fullscreen (F key)';
        document.documentElement.requestFullscreen().catch(err => {
            console.error(`Error attempting to enable full-screen mode: ${err.message} (${err.name})`);
        });
        showSlide(0); // Go to first slide in fullscreen
    } else {
        body.classList.remove('fullscreen-mode');
        fullscreenBtn.innerHTML = '<i class="fas fa-expand"></i>';
        fullscreenBtn.title = 'Enter Fullscreen (F key)';
        if (document.fullscreenElement) {
            document.exitFullscreen();
        }
    }
});

// Sync with browser's native fullscreen exit (e.g., Esc key)
document.addEventListener('fullscreenchange', () => {
    if (!document.fullscreenElement) {
        body.classList.remove('fullscreen-mode');
        fullscreenBtn.innerHTML = '<i class="fas fa-expand"></i>';
        fullscreenBtn.title = 'Enter Fullscreen (F key)';
    }
});

// Dark Mode Toggle
darkModeToggle.addEventListener('click', () => {
    body.classList.toggle('dark-mode');
    if (body.classList.contains('dark-mode')) {
        localStorage.setItem('darkMode', 'enabled');
        darkModeIcon.classList.replace('fa-moon', 'fa-sun');
        darkModeToggle.title = 'Switch to Light Mode';
    } else {
        localStorage.setItem('darkMode', 'disabled');
        darkModeIcon.classList.replace('fa-sun', 'fa-moon');
        darkModeToggle.title = 'Switch to Dark Mode';
    }
});

// Enhanced keyboard navigation
document.addEventListener('keydown', (e) => {
    if (body.classList.contains('fullscreen-mode')) {
        if (e.key === 'ArrowRight' || e.key === ' ') {
            e.preventDefault();
            nextSlide();
        } else if (e.key === 'ArrowLeft') {
            e.preventDefault();
            prevSlide();
        } else if (e.key === 'Home') {
            e.preventDefault();
            showSlide(0);
        } else if (e.key === 'End') {
            e.preventDefault();
            showSlide(slides.length - 1);
        }
    }
    // Toggle fullscreen with 'f' key (but not when typing in an input)
    if (e.key.toLowerCase() === 'f' && e.target.tagName.toLowerCase() !== 'input') {
        e.preventDefault();
        fullscreenBtn.click();
    }
});

// Expert Level Calculator
window.calculateExpertLevel = function() {
    const languages = parseInt(document.getElementById('languages').value) || 0;
    const algorithms = parseInt(document.getElementById('algorithms').value) || 0;
    const dataStructures = parseInt(document.getElementById('dataStructures').value) || 0;
    let score = (languages * 10) + (algorithms * 5) + (dataStructures * 7);
    let level = "Novice Programmer";
    let emoji = "🌱";
    
    if (score >= 200) {
        level = "Programming Guru!";
        emoji = "🧙‍♂️";
    } else if (score >= 150) {
        level = "Advanced Engineer";
        emoji = "🚀";
    } else if (score >= 100) {
        level = "Skilled Developer";
        emoji = "💻";
    } else if (score >= 50) {
        level = "Apprentice Coder";
        emoji = "🔧";
    }
    
    const outputDiv = document.getElementById('expertOutput');
    outputDiv.innerHTML = `
        <div class="text-center">
            <div style="font-size: 3rem; margin-bottom: 10px;">${emoji}</div>
            <strong>Your Programming Expert Score: ${score}</strong><br>
            <strong>Your Expert Level: ${level}</strong>
        </div>
    `;
    outputDiv.style.display = 'block';
};

// Add some interactive tooltips for buttons
fullscreenBtn.title = 'Enter Fullscreen (F key)';
darkModeToggle.title = 'Switch to Dark Mode';